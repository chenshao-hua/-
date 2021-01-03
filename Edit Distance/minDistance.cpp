/*
题目描述:
给定两个字符串,已知可以进行删除、替换和插入任意字符串的任意字符,求最少编辑几步可以将两个字符串变得相同.

Example 1:
Input:word1="horse",word2="ros"
Output:3
在这个样例中,一种最优编辑方法是
（1）horse->rorse
（2）rorse->rose
（3）rose->ros

解题思路:
可以使用动态规划算法,使用一个二维数组dp[i][j],表示将第一个字符串到位置i为止,和第二个字符串到位置j为止,
最多需要几步编辑.当第i位和第j位对应的字符相同时,dp[i][j]等于dp[i-1][j-1];当二者对应的字符不同时,修改
的消耗是dp[i-1][j-1]+1,插入i位置/删除j位置的消耗是dp[i][j-1]+1,插入j位置/删除i位置的消耗是
dp[i-1][j]+1.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    int minDistance(string word1,string word2){
        int m=word1.size(),n=word2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i==0){
                    dp[i][j]=j;
                }else if(j==0){
                    dp[i][j]=i;
                }else{
                    dp[i][j]=min(dp[i-1][j-1]+((word1[i-1]==word2[j-1])?0:1),min(dp[i-1][j]+1,dp[i][j-1]+1));
                }
            }
        }
        return dp[m][n];
    }
};
int main(int argc,char* argv[]){
    string word1="horse",word2="ros";
    cout<<Solution().minDistance(word1,word2)<<endl;
    return 0;
}