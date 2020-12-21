/*
Write an efficient algorithm that searches for a value in an mxn matrix.
This matrix has the following properties:
Integers in each row are sorted in aascending from left to right.
Integers in each column are sortedd in ascending from top to bottom.
For example,
Consider the following matrix:
[[1,4,7,11,15],
[2,5,8,12,19],
[3,6,9,16,22],
[10,13,14,17,24],
[18,21,23,26,30]]
Given target=5,return true.
Given target=20,return false.

题目大意:
给定一个二维矩阵,已知每行每列都是增序的,设计算法快速查找目标值是否存在于矩阵之中.

解题思路:
这道题有个便捷的方式,任选一个角度,可以从右上角开始进行查找,若当前值大于target,则向左移动一位;
若当前值小于target,则向下移动一位.如果最终移到左下角没有找到target,则不存在.
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    bool searchMatrix(vector<vector<int>>& matrix,int target){
        if(matrix.empty())
           return false;
        int m=matrix.size(),n=matrix[0].size(),i=0,j=n-1;
        while(i<m&&j>=0){
            if(matrix[i][j]==target){
                return true;
            }else if(matrix[i][j]>target){
                j--;
            }else{
                i++;
            }
        }
        return false;
    }
};

int main(int argc,char* argv[]){
    vector<vector<int>> matrix={{1,4,7,11,15},
                                {2,5,8,12,19},
                                {3,6,9,16,22},
                                {10,13,14,17,24},
                                {18,21,23,26,30}};
    cout<<Solution().searchMatrix(matrix,20)<<endl;
    return 0;
}