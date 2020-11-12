/*
给您不同面额的硬币和总金额.编写一个函数来计算组成该数量所需的最少数量的硬币.
如果这笔钱不能用硬币的任何组合弥补，则返回-1.

Example 1:
coins = [1, 2, 5], amount = 11
return 3 (11 = 5 + 5 + 1)

Example 2:
coins = [2], amount = 3
return -1.

解题思路：
递归算法不可取，会导致大量的数据重复计算。优先选择动态规划
*/



#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution{
public:
    Solution(vector<int>& _nums,const int& _target):nums(_nums),target(_target){}
    int coinCount(){
        vector<int> dp(target+1,0);
        for(int i=1;i<=target;i++){
            /*满足初始条件*/
            dp[i]=INT_MAX;
            for(int j=0;j<nums.size();j++){
                /*满足边界情况*/
                if(i>=nums[j]&&dp[i-nums[j]]!=INT_MAX){
                    /*转移方程*/
                    dp[i]=min(dp[i-nums[j]]+1,dp[i]);
                }
            }
        }
        if(dp[target]==INT_MAX)
            return -1;
        return dp[target];
    }
private:
    vector<int> nums;
    int target;
};

int main(int argc,char* argv[]){
    vector<int> nums={2,5,7};
    Solution solu(nums,13);
    cout<<solu.coinCount()<<endl;
    return 0;
}