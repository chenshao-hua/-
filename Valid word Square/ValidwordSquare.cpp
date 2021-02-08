/*
Given a sequence of words,check whether it forms a valid word square.
A sequence of words forms a valid word square if the kth row and column read the exact same 
string,where 0<=k<max(numRows,numColumns).
Note:
1.The number of words given is at least 1 and does not exceed 500.
2.Word length will be at least 1 and does not
exceed 500.
3.Each word contains only lowercase English 
alphabet a-z.

Example 1:
Input:["abcd",
       "bnrt",
       "crmy",
       "dtye"]
Output:true

Explanation:
The first row and first column both read "abcd".
The second row and second column both read "bnrt".
The third row and third column both read "crmy".
The fourth row and fourth column both read "dtye".

Example 2:
Input:["abcd",
       "bnrt",
       "crm",
       "dt"]
Output:true

Explanation:
The first row and first column both read "abcd".
The second row and second column both read "bnrt".
The third row and third column both read "crm".
The fourth row and fourth column both read "dt".
题目大意:
给你一个单词序列,判断其是否形成了一个有效的单词方块.
有效的单词方块是指此由单词序列组成的文字方块的第k行和第k列(0≤k<max(行数,列数))所显示的字符串完全相同.

解题思路:
方法一:
行列相等则当个字符在沿着对角线上是对称的.
显而易见,这道题分别遍历ans[n][i]与ans[i][n]是否相等.需要注意的时,当字符串的字符个数小于数组的个数时,
进行加空格.

*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution{
public:
    bool validWordSquare(vector<string>& words){
        int n=words.size();
        vector<vector<char>> ans(n,vector<char>(n,' '));
        for(int i=0;i<n;i++){
            if(words[i].size()>n)  return false;
            if(words[i].size()<n){
                words[i]+=string(n-words[i].size(),' ');//补充空格字符
            }
        }
        bool flag=true;
        for(int k=0;k<n;k++){
            for(int i=k+1;i<n;i++){
                 if(words[k][i]!=words[i][k]){
                    flag=false;
                    break;
                }
            }
        }
        return flag;
    }
};


int main(int argc,char* argv[]){
    vector<string> words={"abcd","bnrt","crmy","dtye"};
    cout<<Solution().validWordSquare(words)<<endl;
    return 0;
}