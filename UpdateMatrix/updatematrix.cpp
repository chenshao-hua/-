/*
给定一个由0和1组成的二维矩阵,求每个位置到最近0的距离.两个相邻元素间的距离为1. 

示例 1
Input:[[0,0,0],
       [0,1,0],
       [1,1,1]]
Output:[[0,0,0],
        [0,1,0],
        [1,2,1]]

解题思路:
方法1
动态规划,先从左上到右下进行一次动态搜索,再从右下到左上进行一次动态搜索.
两次动态搜索即可完成四个方向上的查找.首先找出所有0的节点,它们的距离是0,直
接更新就好了;其他的节点我们更新距离为无限远（用INT_MAX-1表示,减1是为了
防止溢出);从0的位置出发逐步更新周围的点到0的距离;在获得新点的时候要判断
新点是否符合边界要求.

方法2
通常情况下,这样的问题往往涉及到四个方向上的最近搜索,通过对所有为0的元
素的上下左右四个方向进行BFS遍历,若不越界的情况下满足可更新条件,便将其
进行更新,然后将该元素入,更新该元素的上下左右,所有的都更新.

*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
class Solution1{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix){
        if(matrix.empty())
            return {};
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,INT_MAX-1));
        
        /*从左上角到右下角*/
        for(auto i=0;i<n;i++){
            for(auto j=0;j<m;j++){
                if(matrix[i][j]==0){
                    dp[i][j]=0;
                }else{
                    cout<<i<<","<<j<<" "<<dp[i][j]<<endl;
                    if(j>0)
                        dp[i][j]=min(dp[i][j],dp[i][j-1]+1);
                    if(i>0)
                        dp[i][j]=min(dp[i][j],dp[i-1][j]+1);
                }
            }
        }

        /*从右下角到左上角*/
        for(auto i=0;i<n;i++){
            for(auto j=0;j<m;j++){
                if(matrix[i][j]!=0){
                    if(j<m-1)
                        dp[i][j]=min(dp[i][j],dp[i][j+1]+1);
                    if(i<n-1)
                        dp[i][j]=min(dp[i][j],dp[i+1][j]+1);
                }
            }
        }

        return dp;
    }
};

class Solution2{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix){
        if(matrix.empty())
            return {};
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>> ans(n,vector<int>(m,INT_MAX-1));
        queue<pair<int,int>> board;
        for(auto i=0;i<n;i++){
            for(auto j=0;j<m;j++){
                if(matrix[i][j]==0){
                    board.push({i,j});
                    ans[i][j]=0;
                }
            }
        }

        while(!board.empty()){
            auto temp=board.front();
            board.pop();
            for(auto i=0;i<4;i++){
                int x=temp.first+dir[i],y=temp.second+dir[i+1];
                if(x>=0&&x<n&&y>=0&&y<m&&ans[x][y]>ans[temp.first][temp.second]+1){
                    ans[x][y]=ans[temp.first][temp.second]+1;
                    board.push({x,y});/*该点为非零点,入队*/
                }
            }
        }
        return ans;
    }

private:
    vector<int> dir{-1,0,1,0,-1};
};
int main(int argc,char* argv[]){
    vector<vector<int>> matrix={{0,0,0},{0,1,0},{1,1,1}};
    vector<vector<int>> ans=Solution2().updateMatrix(matrix);
    cout<<"变更后的矩阵"<<endl;
    for_each(ans.begin(),ans.end(),[](vector<int>& res){
        cout<<"[ ";
        for(const int& i:res)
           cout<<i<<" ";
        cout<<"]"<<endl;
    });
    return 0;
}
