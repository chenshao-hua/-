/*
题目描述:
给定一个大小为n的正方形国际象棋盘,求有多少种方式可以放置n个皇后并使得她们互相
不攻击,即每一行、每一列、左斜、右斜最多只有一个皇后.

示例 :
Input:4
Output:[[".Q.."],
        ["...Q"],
        ["Q..."],
        [".Q.."]] 或者
        [["..Q."],
         ["Q..."],
         ["...Q"],
         [".Q.."]]
在这个样例中,点代表空白位置,Q代表皇后.

解题思路:
利用回溯的思想,对每一行、列、对角线上方建立访问数组,记录是否存在皇后.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution{
public:
    Solution(const int& _n):n(_n){}
    vector<vector<string>> solveNQueens(){
        vector<string> board(n,string(n,'.'));/*初始化n个字符串("..."),一个字符串n个点*/
        vector<vector<string>> ans;
        if(n==0)
          return ans;
        backtrack(ans,board,0);
        return ans;
    }

private:
    const int n;
    
    void backtrack(vector<vector<string>>& ans,vector<string>& board,int row){
        if(row==n){
            ans.push_back(board);
            return;
        }
        for(auto col=0;col<n;col++){
            if(IsValid(board,row,col)){              
                board[row][col]='Q'; 
                backtrack(ans,board,row+1);
                board[row][col]='.';
            }
        }
    }
    bool IsValid(vector<string>& board,int i,int j){
        /*判断当前位置(i,j)是否合理,只能小于i的值*/
        for(auto row=0;row<i;row++){
            if(board[row][j]=='Q'){/*判断同一列*/
                return false;                
            }
        }       
        /*判断对角线45度*/
        for(auto row=i-1,col=j-1;row>=0&&col>=0;row--,col--){
            if(board[row][col]=='Q')
              return false;
        }
        /*判断对角线135度*/  
        for(auto row=i-1,col=j+1;row>=0&&col<n;row--,col++){
            if(board[row][col]=='Q')
              return false;
        }       
        return true;
    }
};
int main(int argc,char* argv[]){
    int n=4;
    Solution so(n);   
    vector<vector<string>> ans=so.solveNQueens();
    for_each(ans.begin(),ans.end(),[](vector<string>& res){
        cout<<"[ "<<endl;
        for(auto& it:res)
           cout<<"[ "<<it<<" ]"<<endl;
        cout<<" ]"<<endl;
    });
    return 0;
}