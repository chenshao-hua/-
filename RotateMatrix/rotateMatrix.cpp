/*
题目描述:
给你一副由N*N矩阵表示的图像,其中每个像素的大小为4个字节.请你设计一种算法,
将图像旋转90度.
可以不占用额外数组的内存空间？

示例 1:
Input:matrix=[[1,2,3],
              [4,5,6],
              [7,8,9]]
Output:[[7,4,1],
        [8,5,2],
        [9,6,2]]              

示例 2:
Input:matrix=[[5,1,9,11],
              [2,4,8,10],
              [13,3,6,7],
              [15,14,12,16]
Output:[[15,13,2,5],
        [14,3,4,1],
        [12,6,8,9],
        [16,7,10,11]]  

解题思路:
方法1:
借助额外数组存放旋转后的元素,旋转前的元素坐标为:(row,col),旋转后的元素坐标
为:(col,n-1-row),即m(row,col)=m(col,n-1-row)            

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    void rotatematrix(vector<vector<int>>& matrix){
        if(matrix.empty())
           return;
        auto n=matrix.size();
        vector<vector<int>> ans(n,vector<int>(n));
        for(auto i=0;i<n;i++){
            for(auto j=0;j<n;j++){
                ans[j][n-1-i]=matrix[i][j];
            }
        }
        copy(ans.begin(),ans.end(),matrix.begin());/*以追加的方式back_inserter*/
    }

};
int main(int argc,char* argv[]){
    vector<vector<int>> matrix={{1,2,3},{4,5,6},{7,8,9}};
    Solution().rotatematrix(matrix);
    for_each(matrix.begin(),matrix.end(),[](vector<int>& res){
        cout<<"[ ";
        for(auto& num:res)
           cout<<num<<" ";
        cout<<"]"<<endl;
    });
    return 0;
}