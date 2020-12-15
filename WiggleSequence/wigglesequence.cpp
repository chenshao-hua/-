/*
A sequence of number is called a wiggle sequence if the differeces
between successive numbers strictly alternative between positive and 
negative.The frist differece(if one exists)may be either positive or
negative.A sequence with fewer than two elements is trivially a
wiggle sequence.
For example,[1,7,4,9,2,5] is a wiggle sequence because the differences
(6,-3,5,-7,3) are the alternately positive and negative.In contrast,[1,4,7,2,5]
and[1,7,4,5,5] are not wiggle sequences,the first because its first two 
differences are positive and the second because its last difference is zero.

Given a sequence fo integers,return the length of the longest subsequence that 
is a wiggle sequence.A subsequence that is a wiggle sequence.A subsequence is 
obtained by deleting some number of elements(eventually,also zero)from the original
sequeence,leaving the remaining elements in their original order.

Example 1:
Input:[1,7,4,9,2,5]
Output:6

Example 2:
Input:[1,2,3,4,5,6,7,8,9]
Output:2

Example 3:
Input:[1,17,5,10,13,15,10,5,16,8]
Output:7
There are several subsequences that achieve this length,One is[1,17,10,13,10,16,8]

解题思路:
方法1
该题的本质是:在一个单调(递增或者递减)区间内,只保留两头的节点,去掉中间节点.
动态规划的思想,设置两个数组up[i]、down[i],分别,记录到第i个元素为止,以升序和降序结束时
的最长“摆动”序列长度.

方法2
贪心算法
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    int wiggleMaxLength(vector<int>& nums){
        auto n=nums.size();
        if(n==0||n==1) return n;
        vector<int> up(n),down(n);
        up[0]=down[0]=1;
        for(auto i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                up[i]=down[i-1]+1;
                down[i]=down[i-1];
            }else if(nums[i]<nums[i-1]){
                down[i]=up[i-1]+1;
                up[i]=up[i-1];
            }else{
                up[i]=up[i-1];
                down[i]=down[i-1];
            }
        }
        return max(up[n-1],down[n-1]);
    }

    int greedyway(vector<int>& nums){
        auto n=nums.size();
        if(n<=1) return n;
        auto ans=1,old_num=-1;
        for(auto i=1;i<n;i++){
            if(nums[i]==nums[i-1])
               continue;
            int new_num=nums[i]>nums[i-1];
            if(new_num!=old_num)
               ans++;
            old_num=new_num;
        }
        return ans;
    }
};

int main(int argc,char* argv[]){
    vector<int> nums{1,17,5,10,13,15,10,5,16,8};
    cout<<Solution().wiggleMaxLength(nums)<<endl;
    cout<<Solution().greedyway(nums)<<endl;
    return 0;
}