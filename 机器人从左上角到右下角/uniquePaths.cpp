/*
题目描述：
一个机器人位于一个mxn网格的左上角.（起始点在(0,0)标记为“Start” ）。
机器人每次只能向下或者向右移动一步.机器人试图达到网格的右下角（在终点(m-1,n-1)中标记为“Finish”）。
问总共有多少条不同的路径？

解题思路：
动态规划
*/

#include <iostream>
#include <vector>

using namespace std;
class Solution{
public:
    Solution(const int&_m,const int&_n){
        this->m=_m;
        this->n=_n;
    }
    int uniquePath(){
        vector<vector<int>> dp(m,vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0||j==0)
                   dp[i][j]=1;/*初始条件，边界*/
                else
                   /*转移方程*/
                   dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
private:      
    int m,n;
};

int main(int argc,char* argv[]){
    Solution solu(1,3);
    cout<<solu.uniquePath()<<endl;
    return 0;
}