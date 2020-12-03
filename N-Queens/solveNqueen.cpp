/*
可以借助key-value的思想，用一个数组存储,其中索引代表行,值对应的是列,
45度、135度的两个坐标之差的绝对值相等
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution{
public:
    vector<vector<string>> solveNqueen(const int& n){
        vector<vector<string>> ans;
        vector<int> res(n,-1);
        backtrack(res,0,n,ans);
        return ans;
    }

private:
    void backtrack(vector<int>& res,int row,int n,vector<vector<string>>& ans){     
        if(row==n){
            vector<string> board(n,string(n,'.'));
            for(auto i=0;i<n;i++)
               board[i][res[i]]='Q';
            ans.push_back(board);
            return;
        }else{
            for(auto col=0;col<n;col++){
                if(IsValid(res,row,col)){
                    res[row]=col;
                    backtrack(res,row+1,n,ans);
                    res[row]=-1;
                }
            }
        }
    }
    bool IsValid(vector<int>& res,int row,int col){
        for(auto i=0;i<row;i++){
            if(col==res[i]||abs(row-i)==abs(col-res[i]))
               return false;
        }
        return true;
    }
};
int main(int argc,char* argv[]){
    auto n=4;
    vector<vector<string>> ans=Solution().solveNqueen(n);
    for_each(ans.begin(),ans.end(),[](vector<string> res){
        cout<<"[ "<<endl;
        for(auto& it:res)
           cout<<"[ "<<it<<" ]"<<endl;
        cout<<" ]"<<endl;
    });
    return 0;
}