/*
题目描述:
给定一个数组,求这个数组中连续且等差的子数组一共有多少个.注意:这里的子数组
个数满足大于或等于3.

示例 1
Input:nums=[1,2,3,4]
Output:3

在这个样例中,等差数列有:[1,2,3]、[2,3,4]和[1,2,3,4]

解题思路:
这道题要求等差数列,可以自然想到子树组必定满足:
nums[i]-nums[i-1]=nums[i-1]-nums[i-2].然而由于对于dp数组的定义通常
以i结尾的,满足某些条件的子数组数量,而等差数列可以任意一个位置终结,因此此题
在最后需要对dp求和.状态方程满足:dp[i]=dp[i-1]+1
*/
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution{
public:
    int numberOfArithmeticSlics(const vector<int>& nums){
        auto value=nums.size();
        if(value<3)
           return 0;
        vector<int> dp(value,0);
        for(auto i=0;i<value;i++){
            if(nums[i]==2*nums[i-1]-nums[i-2])
                dp[i]=dp[i-1]+1;
        }
        return accumulate(dp.begin(),dp.end(),0);
    }
};

int main(int argc,char* argv[]){
    vector<int> nums{1,2,3,4,5};
    cout<<Solution().numberOfArithmeticSlics(nums)<<endl;
    return 0;
}