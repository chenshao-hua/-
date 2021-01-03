/*
You are given coins of different denominations and a total amount of money amount.
Write a function to compute the fewest number of coins that you need make up that 
amount.If that amount of money cannot be made up by any combination of the coins,
return -1.

Example 1:
Input:coins=[1,2,5],amount=11
Ouput:3(11=5+5+1)

Example 2:
Input:coins=[2],amount=3
Output:-1

Note:
You may assume that you have an infinite number of each kind of coin.

题目大意:
给定一些硬币的面额,求最少可以用多少颗硬币组成给定的金额.

解题思路:
因为每个硬币可以使用无限次数,这道题本质上是完全背包的问题.可以直接展示二维空间压缩为一维的写法.
这里把dp数组初始化为amount+2而不是-1的原因是,在动态规划过程中有求最小值的操作,如果初始化成-1
则会导致结果始终为-1.至于为什么取这个值,是因为i的最大取值为amount+1,而最多的组成方式是只用
1元硬币,因此amount+2一定大于所有的可能的组合方式.在dp后,若结果仍为此值,则说明不存在满足添加的组合
方法,返回-1.
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int coinChange(vector<int>& coins,int amount){
        if(coins.empty())
           return -1;
        vector<int> dp(amount+1,amount+2);
        dp[0]=0;
        for(auto i=1;i<=amount;i++)
            for(const int& coin:coins){
                if(i>=coin){
                    dp[i]=min(dp[i],dp[i-coin]+1);
                }  
            }
        return dp[amount]==amount+2?-1:dp[amount];
    }
};

int main(int argc,char** argv){
    vector<int> coins={1,2,5};
    cout<<Solution().coinChange(coins,11)<<endl;
    return 0;
}