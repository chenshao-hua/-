/*
Given an mxn board and a word,find if the word exists in the word.

The word can be constructed from letters of sequentially "adjacents" cells,
where "adjacents" cells are horizontally or vertically neighboring.The same
cell may not be used more than once.

Example 1:
Input:board=[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]],word="ABCCED"
Output:true

Example 2:
Input:board=[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]],word = "ABCB"
Output:false


解题思路:
利用回溯法可以
*/
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution{
public:
    bool exist(vector<vector<char>>& board,string word){
        m=board.size();
        assert(m>0);
        n=board[0].size();
        visited=vector<vector<bool>>(m,vector<bool>(n,false));
        for(auto i=0;i<board.size();i++){
            for(auto j=0;j<board[0].size();j++){
                if(searchWord(board,word,0,i,j))
                    return true;
            }
        }
        return false;
    }
private:
    int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
    int m,n;
    bool inArea(int x,int y){
        return x>=0&&x<m&&y>=0&&y<n;
    }
    vector<vector<bool>> visited;
    /*从board[x][y]开始,寻找word[index...word.size()-1]*/
    bool searchWord(const vector<vector<char>>& board,const string& word,int index,int x,int y){
        if(index==word.size()-1){
            return board[x][y]==word[index];
        }
        if(board[x][y]==word[index]){
            visited[x][y]=true;
            /*从x,y四个方向寻找*/
            for(auto i=0;i<4;i++){
                int n_x=x+dir[i][0],n_y=y+dir[i][1];
                if(inArea(n_x,n_y)&&!visited[n_x][n_y]&&searchWord(board,word,index+1,n_x,n_y))
                       return true;
            }
            visited[x][y]=false;
        }
        return false;
    }
};

int main(int argc,char* argv[]){
    vector<vector<char>> board={{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    cout<<Solution().exist(board,"ABCB")<<endl;
    return 0;
}