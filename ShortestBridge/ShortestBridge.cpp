/*
给定一个二维0-1矩阵,其中1表示陆地,0表示海洋,每个位置与上下左右相连.岛是由
四面相连的1形成的一个最大组.已知矩阵存在两个岛屿,求最少要填造陆多少个
位置才可以将两个岛屿相连.

示例 1:
Input:[[1,1,1,1,1],
       [1,0,0,0,1],
       [1,0,1,0,1],
       [1,0,0,0,1],
       [1,1,1,1,1]]
Output:1

示例 2:
Input:[[0,1],
       [1,0]]
Output:2

示例 3:
Input:[[0,1,0],
       [0,0,0],
       [0,0,1]]
Output:2

解题思路:
本题实际上是求两个岛屿间的最短距离,因此可以先通过任意搜索方法找到其中一个岛屿
,然后利用广度优先搜索,查找其与另外一个岛屿的最短距离.
*/
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
class Solution{
public:
    int shortestBridge(vector<vector<int>>& grid){
        int m=grid.size(),n=grid[0].size();
        queue<pair<int,int>> points;

        /*dfs寻找第一个岛屿,并把1赋值为2,并把其周边的海洋入队*/
        bool flag=false;
        for(int i=0;i<m;i++){
            if(flag) break;
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    dfs(points,grid,m,n,i,j);
                    flag=true;
                    break;
                }
            }
        }

        /*bfs寻找第二个岛屿,并把过程中经过的0赋值给2*/
        int x,y,count=0;
        while(!points.empty()){
            ++count;
            auto n_points=points.size();
            while(n_points--){
                //auto [r,c]=points.front();/*c++17*/
                auto point=points.front();
                int r=point.first,c=point.second;
                points.pop();
                for(int k=0;k<4;++k){
                    x=r+direction[k],y=c+direction[k+1];
                    if(x>=0&&y>=0&&x<m&&y<n){
                        if(grid[x][y]==2)
                           continue;
                        if(grid[x][y]==1)
                           return count;
                        points.push({x,y});
                        grid[x][y]=2;
                    }
                }
            }
        }
        return 0;
    }
private:
    vector<int> direction{-1,0,1,0,-1};
    void dfs(queue<pair<int,int>>& points,vector<vector<int>>& grid,int m,int n,int i,int j){
        if(i<0||i==m||j<0||j==n||grid[i][j]==2){
            return;
        }
        if(grid[i][j]==0){
            points.push({i,j});
            return;
        }
        grid[i][j]=2;
        dfs(points,grid,m,n,i-1,j);
        dfs(points,grid,m,n,i+1,j);
        dfs(points,grid,m,n,i,j-1);
        dfs(points,grid,m,n,i,j+1);
    }
};

int main(int argc,char* argv[]){
    vector<vector<int>> grid={{0,1,0},{0,0,0},{0,0,1}};  
    cout<<Solution().shortestBridge(grid)<<endl;  
    return 0;
}