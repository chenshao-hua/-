/*
dfs+记忆,利用空间换时间
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution{
public:
    int longestIncreasingPath(vector<vector<int>>& matrix){
        int row=matrix.size(),col=matrix[0].size(),res=0;
        if(row==0||col==0) return 0;
        auto cache=vector<vector<int>>(row,vector<int>(col,0));
        for(int i=0;i<row;++i){
            for(int j=0;j<col;++j){
                res=max(res,dfsPath(matrix,cache,i,j));
            }
        }
        return res;
    }

private:
    const int  dir[5]={-1,0,1,0,-1};
    int dfsPath(vector<vector<int>>& matrix,vector<vector<int>>& cache,int row,int col){
        if(cache[row][col]!=0){
            return cache[row][col];/*已经计算过,直接返回当前值*/
        }
        ++cache[row][col];
        for(int i=0;i<4;++i){
            int x=row+dir[i],y=col+dir[i+1];
            if(isValid(matrix,row,col,x,y)){
                cache[row][col]=max(cache[row][col],dfsPath(matrix,cache,x,y)+1);
            }
        }
        return cache[row][col];
    }

    bool isValid(vector<vector<int>>& matrix,int row,int col,int x,int y){
        if(x>=0&&x<matrix.size()&&y>=0&&y<matrix[0].size()&&matrix[x][y]>matrix[row][col]){
            return true;
        }
        return false;
    }
};
int main(int argc,char* argv[]){
    vector<vector<int>> matrix={{3,4,5},{3,2,6},{2,2,1}};
    /*
    for(auto& v:matrix){
        for(const auto& i:v){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    */
    cout<<Solution().longestIncreasingPath(matrix)<<endl;
    return 0;
}