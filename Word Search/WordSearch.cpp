/*
题目描述：
给定一个字母矩阵,所有的字母都与上下左右四个方向上的字母相连.给定一个字符串,
求字符串能不能在矩阵中寻找到.

示例 :
Input:board=[['A','B','C','E'],
             ['S','F','C','S']
             ['A','D','E','E']],word="ABCCED"
Output:true
从左上角的'A'开始,可以先向右、再向下、最后向左,找到连续的"ABCCED";

解题思路:
不同于排列组合的问题，本题采用的并不是修改输出方式，而是修改访问标记。在我们
对任意位置进行深度优先搜索时，我们先标记当前位置为已访问，已避免重复遍历（可以
防止向右搜索后又向左返回）;在所有的可能都搜索完成后,再回改当前位置为未访问，防止
干扰其它位置的搜索到当前位置.使用回溯法，可以只对一个二维的访问矩阵进行修改,而不是
把每次的搜索状态作为一个新对象传入递归函数中.

*/
#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    Solution(vector<vector<char>>& _charword,string& _word):charword(_charword),word(_word){}
    bool wordsearch(){
        if(charword.empty())
           return false;
        int m=charword.size(),n=charword[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        bool find=false;
        for(auto i=0;i<m;i++){
            for(auto j=0;j<n;j++){
                backtrack(i,j,charword,find,visited,0);
            }
        }
        return find;
    }
private:
    vector<vector<char>> charword;
    string word;
    void backtrack(int i,int j,vector<vector<char>>& board,bool& find,vector<vector<bool>>& visited,int pos){
        if(i<0||i>=board.size()||j<0||j>=board[0].size())
           return;
        if(visited[i][j]||find||board[i][j]!=word[pos])
           return;
        if(pos==word.size()-1){
            find=true;
            return;
        }
        visited[i][j]=true;  /*修改当前节点状态*/
        
        /*递归子节点*/
        backtrack(i+1,j,board,find,visited,pos+1);
        backtrack(i-1,j,board,find,visited,pos+1);
        backtrack(i,j+1,board,find,visited,pos+1);
        backtrack(i,j-1,board,find,visited,pos+1);
    }
};

int main(int argc,char* argv[]){
    vector<vector<char>> charword={{'A','B','D','E'}, {'S','C','C','S'},{'A','D','E','E'}};
    string word="ABCCED";
    cout<<Solution(charword,word).wordsearch()<<endl;
    return 0;
}