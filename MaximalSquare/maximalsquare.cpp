/*
给定一个二维的0-1矩阵,求全由1构成的最大正方形面积.

Input:[['1','0','1','0','0'],
       ['1','0','1','1','1'],
       ['1','1','1','1','1'],
       ['1','0','0','1','0']]
Output:4

解题思路:
对于在矩阵内搜索正方形或长方形的题型,一种常见的做法是定义一个二维dp数组,
其中dp[i][j]表示满足题目条件的,以(i,j)为右下角的正方形或者长方形的属性.
对于本题,则表示以(i,j)为右下角的全由1构成的最大正方形面积.如果当前位置
是0,那么dp[i][j]为0,若当前位置是1,假设dp[i][j]=k^2,其充分条件
为dp[i-1][j-1]、dp[i][j-1]和dp[i-1][j]的值必须都大于(k-1)^2,
否则(i,j)位置不可以构成一个边长为k的正方形.同理,如果这三个值中的最小值
为k-1,则(i,j)位置一定且最大可以构成一个边长为k的正方形.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    int maxmalsquare(vector<vector<char>>& matrix){
        if(matrix.empty()||matrix[0].empty())
           return 0;
        int row=matrix.size(),col=matrix[0].size(),max_side=0;
        vector<vector<int>> dp(row+1,vector<int>(col+1,0));
        /*避免边界处理,从1开始*/
        for(auto i=1;i<=row;i++){
            for(auto j=1;j<=col;j++){
                if(matrix[i-1][j-1]=='1'){
                    dp[i][j]=min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]))+1;
                }
                max_side=max(max_side,dp[i][j]);
            }
        }
        return max_side*max_side;
    }
};

int main(int argc,char* argv[]){
    vector<vector<char>> matrix={{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    cout<<Solution().maxmalsquare(matrix)<<endl;
    return 0;
}