/*
321.拼接最大数
给定长度分别为m和n的两个数组,其元素由0-9构成,表示两个自然数各位上的数字.现在
从这两个数组中选出k(k<=m+n)个数字拼接成一个新的数,要求从同一个数组中
取出的数字保持其在原数组中的相对顺序.求满足该条件的最大数.结果返回一个
表示该最大数的长度为k的数组.
说明:请尽可能地优化你算法的时间和空间复杂度.

示例 1:
Input:nums1=[3,4,6,5],nums2=[9,1,2,5,8,3],k=5
Output:[9,8,6,5,3]

示例 2:
Input:nums1=[6,7],nums2=[6,0,4],k=5
Output:[6,7,6,0,4]

示例 3:
Input:nums1=[3,9],nums2=[8,9],k=3
Input:[9,8,9]
*/

/*
字典序比较算法
（1）序列的字典序比较:从第一位开始分别比较对应的元素,若分出大小则返回结果,
否则继续进行下一位的大小的比较;
（2）vector的默认比较操作即为字典序比较;
（3）STL的lexicographical_compare()算法可以按照字典序比较由开始结束迭代器定义两个序列;

单调栈
（1）单调栈:就是栈内元素单调按照递增(递减)顺序排列的栈;
（2）单调栈的实现:可以使用vector来实现栈的操作,vector可以在末尾快速
的添加和删除元素,并且方便栈内的元素读取;

/*
vector<int> ans;//单调栈
for(auto& num:ans){
    //当前元素大于栈顶元素,则出栈、直到满足单调性
    while(ans.size()||num>ans.back())
       ans.pop_back();//末尾元素删除
    //当前元素入栈
    ans.push_back();
}
*/

/*
解题思路:
（1）该题的本质即为从两个数组中挑选k个元素,并且使得拼接后的结果字典序
达到最大.
（2）要使数组的字典序最大,则需要保证从左到右的每一个位置的值尽可能的大,
即单调递减.
（3）枚举所有的k的组合情况,分别从两个数组中取i、j个元素构成的最大数组,满足
i+j=k,然后再进行合并,最终保留最大值.
（4）在挑选指定个数的元素过程中,若当前挑选的元素数量大于需要的个数,则进行取舍
操作,以使每个位置的值尽可能的大.
（5）合并过程中,分别从头到尾遍历两个数组比较当前元素优先取较大值作为合并结果;
若当前位置相等,则需要进行下一位比较,以确保下一位可选的元素值最大.

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    vector<int> maxNumber(vector<int>& nums1,vector<int>& nums2,int k){
        vector<int> ans(k);
        /*从nums1取出第i个元素*/
        for(auto i=0;i<=nums1.size();i++){
            /*最多取k个*/
            if(i>k)
               break;
            /*nums中取剩余的*/
            if(k-i<=nums2.size()){
                vector<int> res1=getMax(nums1,i);
                vector<int> res2=getMax(nums2,k-i);
                vector<int> res=vec2meger(res1,res2);
                ans=vec2max(ans,res);
            }
        }
        return ans;
    }

private:
    /*从数组中取n个数字,并保持相对顺序,构成最大*/
    vector<int> getMax(vector<int>& nums,int n){
        /*数字最大则从左到右每一位可能大,即单调递减*/
        vector<int> res;
        int total=nums.size();
        auto remain=total-n;/*允许丢掉的元素个数*/
        for(auto& num:nums){
            /*若下个元素比当前元素的值大,则可以选择舍弃当前元素*/
            /*但是,可以舍弃的元素小于1时,表示不能再舍弃元素了,只能添加*/
            while(res.size()>0&&remain>0&&num>res.back()){
                remain--;/*允许丢掉的元素减1*/
                res.pop_back();/*末尾删除元素*/
            }
            if(res.size()<n){
                res.push_back(num);/*未取够n个元素*/
            }else{
                remain--;/*已经取够k个,直接丢弃*/
            }
        }
        return res;
    }

    /*合并两个数组*/
    vector<int> vec2meger(vector<int>& nums1,vector<int>& nums2){
        /*若两个位置元素相等时,需要对下一位进行比较,以使得下一位最大*/
        vector<int> res;
        int i=0,j=0;
        while(i<nums1.size()&&j<nums2.size()){
            /*取最大的,该STL里面的容器函数比较数组大小,返回true或false*/
            /*vector<int>(nums1.begin()+i,nums1.end())<vector<int>(nums2.begin()+j,nums2.end())*/
            /*lexicographical_compare默认值是"<"小于符号*/
            if(!lexicographical_compare(nums1.begin()+i,nums1.end(),nums2.begin()+j,nums2.end())){
                res.push_back(nums1[i]);
                i++;
            }else{
                res.push_back(nums2[j]);
                j++;
            }
        }
        /*拷贝剩余元素到数组中*/
        copy(nums1.begin()+i,nums1.end(),back_inserter(res));
        copy(nums2.begin()+j,nums2.end(),back_inserter(res));
        return res;       
    }
    
    /*比较两个数组的大小*/
    vector<int> vec2max(vector<int>&nums1,vector<int>&nums2){;
        vector<int> res;
        for(auto i=0;i<nums1.size();i++){
            if(nums1[i]>nums2[i]){
                res=nums1;
                break;
            }else if(nums1[i]==nums2[i]){
                continue;
            }else{
                res=nums2;
                break;
            }
        }
        return res;
    }
};

int main(int argc,char* argv[]){
    vector<int> nums1={3,4,6,5},nums2={9,1,2,5,8,3};
    vector<int> ans=Solution().maxNumber(nums1,nums2,5);
    for(auto& num:ans)
        cout<<num<<" ";
    cout<<endl;
    return 0;
}