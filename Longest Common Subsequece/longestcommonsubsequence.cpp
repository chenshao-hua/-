/*
Given two strings text1 and text2,return the length of their longest common subsequence.
A subsequence of a string is a new string generated from the original string with some
characters(can be none) deleted without changing the relative order of the remaining
character.(eg,"ace" is a subsequence of "abcde" while "aec" is not).A common subsequence
of two strings is a subsequence that is common to both strings.
If there is no common subsequence,return 0.

Example 1:

Input:text1="abcde",text2="ace" 
Output:3  
Explanation:The longest common subsequence is "ace" and its length is 3.

Example 2:
Input:text1="abc",text2="abc"
Output:3
Explanation:The longest common subsequence is "abc" and its length is 3.

题目大意:
最长公共子序列是在不改变原字符串的顺序情况下删除某些(或者不删除)组成新的字符串.求最长公共子序列.

解题思路:
利用动态规划,
（1）若text1的第i个字符与text2的第j个字符相同,那么dp[i][j]=dp[i-1][j-1]+1
（2）若text1的第i个字符与text2的第j个字符不同,那么dp[i][j]=max(dp[i-1][j],dp[i][j-1]).
因为第i个和第j个完全不同,因此不用让它们同时都往前走,只让text2走到j,或者只让text1走到i就足够了.
然后比较那种结果最大,根据求最长公共子序列取最大值.
要注意的是,因为下标会取到dp[i-1][j-1],所以在循环时要从1开始,而不是0.

 
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution{
public:
    int longestcommonsubsequence(string text1,string text2){
        int m=text1.size()+1,n=text2.size()+1;
        vector<vector<int>> dp(m,vector<int>(n));
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m-1][n-1];
    }
};
int main(int argc,char* argv[]){
    string text1="ezupkr",text2="ubmrapg";
    cout<<Solution().longestcommonsubsequence(text1,text2)<<endl;
    return 0;
}