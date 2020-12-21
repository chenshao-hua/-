/*
二维矩阵包围的'o'翻转为'x'
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution{
public:
    void solveregion(vector<vector<char>>& board){
        if(board.empty())
            return;
        /*首行、末行*/
        int m=board.size(),n=board[0].size();
        for(auto i=0;i<m;i++){
            if(board[i][0]=='o'){      
                bfsregion(i,0,board);
            }else if(board[i][n-1]=='o'){
                bfsregion(i,n-1,board);
            }
        }
        /*首列、末列*/
        for(auto j=0;j<n;j++){
            if(board[0][j]=='o'){
                bfsregion(0,j,board);
            }else if(board[m-1][j]=='o'){
                bfsregion(m-1,j,board);
            }
        }
    
        for(auto i=0;i<m;i++){
            for(auto j=0;j<n;j++){
                if(board[i][j]=='*'){
                    board[i][j]='o';
                }else if(board[i][j]=='o'){
                    board[i][j]='x';
                }
            }
        }
        
    }
private:
    int dir[5]={-1,0,1,0,-1};
    void bfsregion(int i,int j,vector<vector<char>>& board){
        queue<pair<int,int>> str;
        str.push(pair<int,int>(i,j));/*或者直接{i,j}*/
        board[i][j]='*';
        while(!str.empty()){
            auto p=str.front();
            str.pop();
            for(auto k=0;k<4;k++){
                int x=p.first+dir[k],y=p.second+dir[k+1];
                if(x<0||x>=board.size()||y<0||y>=board[0].size())
                   continue;
                if(board[x][y]=='o'){
                    str.push(pair<int,int>(x,y));
                    board[x][y]='*';
                }
            }
        }
    }
};
int main(int argc,char* argv[]){
    vector<vector<char>> board={{'x','x','x','x'},{'x','o','o','x'},{'x','x','o','x'},{'x','o','x','x'}};
   
    Solution().solveregion(board); 
    for(auto& k:board){
        for(auto& i:k)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}