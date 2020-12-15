/*
Given a triangle,find the minimum path sum from top to bottom.Each step you may
move to adjacent numbers on the row below.
For example,given the following triangle.
[
    [2],
   [3,4],
  [6,5,7],
 [4,1,8,3]
]
The minimum path sum from top to bottom is 11(2+3+5+1=11);

解题思路:
这道题的意思是求出从三角形顶端到低端的最小和.最好使用O(n)的时间复杂度.
可以直接从下层往上层推进,然后使用一维数组DP动态规划可以解决.需要注意的是每一步
只能移动到下一行中相邻的节点上,也就是说假如上一行节点是dp[i][j],下一行节点只能是
dp[i+1][j],dp[i+1][j+1]
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    int minimumtotal(vector<vector<int>>& triangle){
        if(triangle.empty())
            return 0;
        for(int row=triangle.size()-2;row>=0;row--){
            for(int col=0;col<triangle[row].size();col++){
                triangle[row][col]+=min(triangle[row+1][col],triangle[row+1][col+1]);
            }

        }
        return triangle[0][0];
    }
};
int main(int argc,char* argv[]){
    vector<vector<int>> triangle{{2},{3,4},{6,5,7},{4,1,8,3}};
    cout<<Solution().minimumtotal(triangle)<<endl;
    return 0;
}