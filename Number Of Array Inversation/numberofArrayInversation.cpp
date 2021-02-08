/*
题目描述:
在数组中的两个数字,如果前面一个数字大于后面的数字,则这两个数字组成一个逆序对.输入一个数组,求出这个数组中
的逆序对的总数P.并将P对1000000007取模的结果输出.即输出P%1000000007.

Note:
2<=n<=50000;

Example 1:
Input:nums=[9,6,8,5]
Output:5
Explanation:There are numbers of inversion,like:[9,6],[9,8],[9,5],[6,5],[8,5] 

解题思路:
方法1:
暴力破解,双层遍历,超时.
方法2:
利用分治思想中的归并数组算法.总的逆序对=左半部分逆序对+右半部分逆序对+左边对于右边的逆序对.基于这样设计之所以正确
是因为每一次子序列的排序都是在计算完完该子序列之后,再进行排序的.
假设正在归并上面的数组,左侧的2、3、6、8和右侧的1、4、5、7已经排好序了,左侧和右侧内部都没有逆序对,而从左侧取一个
数,从右侧取一个数,则有可能形成逆序对.
例如,开始左侧拿出2,右侧拿出1,可知2>1,形成了逆序对.此时逆序对只是加1吗？并不是,因为2右边的数都是大于2的,所以可
以判断左边的数和右边的1可以形成4对逆序对（(2,1)、(3,1)、(6,1)、(8,1)）.
接下来比2和4，不会形成逆序对。再比3和4，不会形成逆序对.
当比较到6和4的时候，形成了逆序对，个数为2((6,4)、(8,4)).
归纳一下,也就是在归并的时候,如果右侧的元素小于左侧的元素,这个时候开始统计逆序对就行了,如果左侧的索引为i,左侧的末
尾元素的索引为mid,逆序对个数就为mid-i+1.
这样并没有结束,前面的假设是左侧和右侧是有序的,事实上并不是,左侧和右侧也进行了归并的过程才能变得有序,而在归并过程
中,也能计算出逆序对的个数.
所以:
总的逆序对的个数=左侧归并时求得的逆序对个数+右侧归并时求得的逆序对个数+对整体进行归并时的逆序对个数
可能会怀疑这三种情况会有重复,但是并没有.左侧归并找到的逆序对相当于从左侧数组中取2个数,而整体归并的时候是分别从
左右数组中取1个数,不可能发生重复!
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int numberofArrayInversation(vector<int>& nums){
        if(nums.empty()) return 0;
        vector<int> board(nums.begin(),nums.end());
        return merge_sort(board,nums,0,nums.size()-1);
    }

private:
    int merge_sort(vector<int>& board,vector<int>& nums,int l,int r){
        if(l>=r){
            return 0;
        }
        int mid=(l+r)>>1;
        int l_num=merge_sort(board,nums,l,mid)%1000000007;
        int r_num=merge_sort(board,nums,mid+1,r)%1000000007;
        return (l_num+r_num+merge(board,nums,l,mid,r))%1000000007;
    }
    int merge(vector<int>& board,vector<int>& nums,int l,int mid,int r){
        for(int i=l;i<=r;i++){
            nums[i]=board[i];
        }
        int ans=0,i=l,j=mid+1,k=l;//初始化,i指向左半部分的起始索引位置l,j指向右半部分的起始索引位置mid+1.
        while(k<=r){
            if(i>mid){//左半部分的元素处理完毕
                board[k]=nums[j];
                ++j;
            }else if(j>r){//右半部分的元素处理完毕
                board[k]=nums[i];
                ++i;
            }else if(nums[i]<nums[j]){//左半部分的元素小于右半部分的元素
                board[k]=nums[i];
                ++i;
            }else{//左半部分的元素大于或等于右半部分的元素
                board[k]=nums[j];
                ++j;
                ans+=(mid-i+1);
                ans%=1000000007;
            }
            ++k;
        }
        return ans;
    }
};

int main(int argc,char* argv[]){
    vector<int> nums={9,6,8,5,2,7};
    cout<<Solution().numberofArrayInversation(nums)<<endl;
    return 0;
}