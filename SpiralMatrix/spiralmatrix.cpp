/*
字节、美团真题
给定一个m*n的矩阵,请按顺时针螺旋顺序,返回矩阵中所有的元素.

示例 1:
Input:matrix=[[1,2,3],
              [4,5,6],
              [7,8,9]]
Output:[1,2,3,6,9,8,7,4,5]

示例 2:
Input:matrix=[[1,2,3,4],
              [5,6,7,8],
              [9,10,11,12]]
Output:[1,2,3,4,8,12,11,10,9,5,6,7]

解题思路:
方法1
模拟遍历 
首先需要定义行和列的方向数组,因为当遍历到矩阵的边界时需要换方向.同时遍历
到已经遍历过的元素也需要换方向.
行方向:
dr={0,1,0,-1}(右、下、左、上)
列方向:
dc={1,0,-1,0}(右、下、左、上)
此外,需要设置一个bool数组,进行记录已经遍历过的元素坐标(row,col),以便
进行边界判断.
其实还有更加便捷的方式设置方向:d={0,1,0,-1,0},只需要用一个矩阵

方法2
按层遍历
把这个矩阵像剥洋葱的一层一层的剥开,从最外层一直到最里层,
比如示例1的,
第一层的上面边:1,2,3,其中列坐标col从Mincol到Maxcol;
第一层的右面边:6,9,其中行坐标row从Minrow+1到Maxrow;
第一层的下面边:8,7,其中列坐标col从Maxcol-1到Mincol;
第一层的左面边:4,其中行坐标row从Maxrow-1到Minrow+1;
第二层的上面边:5,其中列坐标col从Mincol到Maxcol
这个理解比较简单,需要注意的点是对当前层是否有4条边的判断:
Minrow<Maxrow&&Mincol<Maxcol,如果不满足就表示当前层没有4条边,就
不需要遍历下面边和左面边.

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    vector<int> spiralorder(vector<vector<int>>& matrix){
        if(matrix.empty())
           return {};
        int row=matrix.size(),col=matrix[0].size();
        vector<int> ans;
        /*行方向*/
        vector<int> dr={0,1,0,-1};
        /*列方向*/
        vector<int> dc={1,0,-1,0};
        int r=0,c=0,k=0;
        /*记录是否访问过*/
        vector<vector<bool>> flag(row,vector<bool>(col));

        for(auto i=0;i<row*col;i++){
            /*标记已经访问过,并放入到结果数组中*/
            flag[r][c]=true;
            ans.push_back(matrix[r][c]);
            /*下一步移动的位置*/
            int nr=r+dr[k],nc=c+dc[k];
            /*判断是否到了边界或者已经访问过*/
            if(nr>=0&&nr<row&&nc>=0&&nc<col&&!flag[nr][nc]){
                r=nr;
                c=nc;
            }else{
                /*已经到了边界或者访问过*/
                k=(k+1)%4;
                r=r+dr[k];
                c=c+dc[k];
            }
        }
        return ans;
    }
};

int main(int argc,char* argv[]){
    vector<vector<int>> matrix={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    vector<int> ans=Solution().spiralorder(matrix);
    cout<<"[ ";
    for(auto& num:ans)
       cout<<num<<" ";
    cout<<"]"<<endl;
    return 0;
}