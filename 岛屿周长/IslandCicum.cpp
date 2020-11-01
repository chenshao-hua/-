/*思路一：网格盘可以理解为直角坐标系的第一象限，默认岛屿的周长为4，只要两个岛屿相邻，则周长必定减少2*/

/*思路二：遍历行列，默认岛屿的周长为4，只要其左或右或上或下出现岛屿，周长就减1*/
#include <iostream>
#include <vector>
using namespace std;


class Solution {
 public:
     int islandPerimeter(vector<vector<int>>& grid) {
        int num = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] == 1) {
                    num = num + 4;   
                    //如果grid[i+1][j]不超出数组并且也等于1（岛）则边减2
                    if(i + 1 < grid.size() && grid[i + 1][j] == 1) {
                        num = num -2;
                    }
                    //如果grid[i][j+1]不超出数组并且也等于1（岛）则边减2
                    if(j + 1 < grid[i].size()&& grid[i][j + 1] == 1) {
                        num = num -2;
                    }
                }
            }
        }
        return num;
    }
};

class _Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) 
    {
        int island_grith = 0;    //周长
        for(int i = 0;i<grid.size();i++) {
            for(int j = 0;j<grid[0].size();j++) {
               if(grid[i][j]==1){
                   island_grith=island_grith+4;                     //默认岛屿周长是4
                   if(j-1 >= 0 && grid[i][j-1] == 1)                //正上方有岛屿
                       island_grith--;                              //周长减1
                   if(j+1 <= grid[0].size()-1 && grid[i][j+1] == 1) //正下方有岛屿
                       island_grith--;
                   if(i-1 >= 0 && grid[i-1][j] == 1)                //左边有岛屿
                       island_grith--;
                   if(i+1 <= grid.size()-1 && grid[i+1][j] == 1)    //右边有岛屿
                       island_grith--;
               }
            }
        }
        return island_grith;
    }
};

int main(){
    vector<vector<int>> grid={{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}};
    Solution IslandCicum;
    cout<<IslandCicum.islandPerimeter(grid)<<endl;
    _Solution _IslandCicum;
    cout<<_IslandCicum.islandPerimeter(grid)<<endl;
    return 0;
}