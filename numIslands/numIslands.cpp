/*
岛屿数量:
给你一个由'1'(陆地)和'0'(水)组成的二维网格,请你计算出网格中的岛屿数量.
岛屿总是被谁包围,并且每座岛屿由水平方向或者竖直方向上相邻的陆地连接形成
的.此外,你可以假设该网格的四条边均被水包围.

示例 1:
Input:grid=[['1','1','1','1','0'],
            ['1','1','0','1','0'],
            ['1','1','0','0','0'],
            ['0','0','0','0','0']]
Output:1

示例 2:
Input:grid=[['1','1','0','0','0'],
            ['1','1','0','0','0'],
            ['0','0','1','0','0'],
            ['0','0','0','1','1']]
Output:3

解题思路:
利用递归遍历即可,这里岛屿的定义不包括对角线上的,先枚举二维数组上各个点,设
置一个递归函数,若当前点为'1',则将岛屿的个数加1并进入递归,遍历水平、垂直
方向的岛屿是否满足'1',并且将'1'的岛屿设置为'0',这样的目的是避免遍历
过程中重复计数,直到不满足条件跳出递归.
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int numIslands(vector<vector<char>>& grid){
        auto IslandNum=0;
        for(auto i=0;i<grid.size();i++){
            for(auto j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    backtrack(grid,i,j);
                    IslandNum++;/*必须放在递归后面*/
                }
            }
        }
        return IslandNum;
    }
private:
    void backtrack(vector<vector<char>>& grid,int i,int j){
        if(i<0||i>=grid.size()||j<0||j>=grid[0].size()||grid[i][j]=='0'){
            return;
        }
        grid[i][j]='0';
        backtrack(grid,i-1,j);
        backtrack(grid,i+1,j);
        backtrack(grid,i,j-1);
        backtrack(grid,i,j+1);
    }
};

int main(int argc,char* argv[]){
    vector<vector<char>> grid={{'1','1','0','0','0'},
                               {'1','1','0','0','0'},
                               {'0','0','1','0','0'},
                               {'0','0','0','1','1'}};
    cout<<Solution().numIslands(grid)<<endl;
    return 0;
}