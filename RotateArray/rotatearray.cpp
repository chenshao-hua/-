/*
给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。

示例 1:

Input:  [1,2,3,4,5,6,7]和k=3
Output: [5,6,7,1,2,3,4]
解释:
向右旋转 1 步:[7,1,2,3,4,5,6]
向右旋转 2 步:[6,7,1,2,3,4,5]
向右旋转 3 步:[5,6,7,1,2,3,4]

示例 2:

Input:  [-1,-100,3,99]和k=2
Output: [3,99,-1,-100]
解释:
向右旋转 1 步: [99,-1,-100,3]
向右旋转 2 步: [3,99,-1,-100]

提示:
尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题;
要求使用空间复杂度O(1)的原地算法;

解题思路:
方法1
从nums[0]开始,每次移动k的位置:即将nums[0]的值移动到nums[0+k],
为了避免超时,需要加一个计数变量count,每次一个位置移动成功之后就进行加1运算,
当满足count的值大小等于数组大小的时候,则证明已经完成旋转.

方法2
采用反转的方法,先反转前n-k个元素,再反转后k个元素,最后将整个数组反转.
需要进过三次反转.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution{
public:
    void rotatevector(vector<int>& nums,int k){
        if(k==0)
           return;
        /*n1、n2临时变量,index每轮移动的下标,count移动计数*/
        int n1,n2,index,count=0;
        k%=nums.size();/*用求余是避免k大于nums.size()*/
        for(auto i=0;i<=k;i++){
            if(count>=nums.size())
               break;
            index=i;
            n1=nums[i];
            while((index+k)%nums.size()!=i){
                count++;
                n2=nums[(index+k)%nums.size()];
                nums[(index+k)%nums.size()]=n1;
                index=(index+k)%nums.size();
                n1=n2;
            }
            nums[i]=n1;
            count++;
        }

    }
    void rotatearray(vector<int>& nums,int k){
        if(k==0)
           return;
        int len=nums.size();
        k%=len;
        reverse(nums.begin(),nums.end()-k);
        reverse(nums.end()-k,nums.end());
        reverse(nums.begin(),nums.end());
    }
};
int main(int argc,char* argv[]){
    vector<int> nums={-1,-100,3,99};
    Solution().rotatearray(nums,2);
    for(auto& i:nums)
       cout<<i<<" ";
    cout<<endl;
    return 0;
}