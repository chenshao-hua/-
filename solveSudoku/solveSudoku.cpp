/*
LeetCode-37 题目描述:

编写一个程序,通过已填充的空格来解决数独问题.
一个数独的解法需遵循如下规则:
空白格用'.'表示;
1.数字1-9在每一行只能出现一次;
2.数字1-9在每一列只能出现一次;
3.数字1-9在每一个以粗实线分隔的3x3九宫格内只能出现一次.

解题思路:
回溯+剪枝
用三个bool型的二维数组L、C、S,其中
（1）L表示第i行是否已经出现j+1这个数字;
（2）C表示第i列是否已经出现j+1这个数字;
（3）S表示第i个3x3九宫格是否已经出现j+1这个数字;
并且每次遇到空白格时,依次尝试1-9的数字前,判断空白格所属的行、列以及3
x3的九宫格是否已经出现该数字（剪枝）,便可保证每次填入数字之后的数独都是
有效的,无需再判断.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
private:
    vector<vector<char>> letter;
    bool backtrack(vector<vector<char>>& board,int position,vector<vector<bool>>& L,vector<vector<bool>>& C,vector<vector<bool>>& S){
        int index=position;
        for(;index<81&&'.'!=board[index/9][index%9];index++);
        
        if(index<81){
            int row=index/9,col=index%9;
            for(auto i=1;i<10;i++){
                if(L[row][i-1]||C[col][i-1]||S[row/3*3+col/3][i-1])
                    continue;
                board[row][col]=(char)('0'+i);
                L[row][i-1]=true;
                C[col][i-1]=true;
                S[row/3*3+col/3][i-1]=true;
                    
                if(backtrack(board,index+1,L,C,S))
                    return true;
                board[row][col]='.';
                L[row][i-1]=false;
                C[col][i-1]=false;
                S[row/3*3+col/3][i-1]=false;
            }
            return false;
        }                   
        return true;/*index=81*/
    }
public:
    Solution(vector<vector<char>>& _letter):letter(_letter){}
    void solveSudoku(){
        /*记录第i行是否包含j+1字符*/
        vector<vector<bool>> L(9,vector<bool>(9,false));
        /*记录第i列是否包含j+1字符*/
        vector<vector<bool>> C(9,vector<bool>(9,false));
        /*记录第i个九宫格是否包含j+1字符*/
        vector<vector<bool>> S(9,vector<bool>(9,false));
        for(auto row=0;row<9;row++){
            for(auto col=0;col<9;col++){
                if('.'==letter[row][col])
                   continue;
                L[row][letter[row][col]-'1']=true;
                C[col][letter[row][col]-'1']=true;
                S[row/3*3+col/3][letter[row][col]-'1']=true;
            }
        }
        backtrack(letter,0,L,C,S);

    }
    void print(){
        for_each(letter.begin(),letter.end(),[](vector<char>& result){
            cout<<"["<<" ";
            for(auto& res:result)
               cout<<res<<" ";
            cout<<"]"<<endl;
        });
    }
};

int main(int argc,char* argv[]){
    vector<vector<char>> letter={{'5','3','.','.','7','.','.','.','.'},
                                 {'6','.','.','1','9','5','.','.','.'},
                                 {'.','9','8','.','.','.','.','6','.'},
                                 {'8','.','.','.','6','.','.','.','3'},
                                 {'4','.','.','8','.','3','.','.','1'},
                                 {'7','.','.','.','2','.','.','.','6'},
                                 {'.','6','.','.','.','.','2','8','.'},
                                 {'.','.','.','4','1','9','.','.','5'},
                                 {'.','.','.','.','8','.','.','7','9'}};
    Solution so(letter);
    so.solveSudoku();
    so.print();
    return 0;
}