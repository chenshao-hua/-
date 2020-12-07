/*
将1到n这n个整数围成一个圆环,若其中任意两个相邻的元素相加,结果为素数,则
这个环就是素数环.

示例 1
Input:nums=6
Output:[1,4,3,2,5,6]

解题思路:
利用回溯+剪枝算法,此外质数的判断巧妙的利用取开方的算法.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution{
public:
    vector<vector<int>> primering(const int& num){
        if(num==1)
           return {{1}};
        vector<int> board;
        vector<bool> IsUsed(num);
        board.push_back(1);
        vector<vector<int>> ans;        
        dfs(ans,board,num,IsUsed,1);
        return ans;
    }
private:
    bool IsPrime(const int& n){
        /*判断是否为素数*/
        if(n==1)
           return true;
        int temp=sqrt(double(n));
        for(auto i=2;i<=temp;i++){
            if(n%i==0)
                return false;
        }
        return true;
    }
    void dfs(vector<vector<int>>& ans,vector<int>& board,const int& num,vector<bool>& IsUsed,int index){
        if(index>=num){
            if(!IsPrime(board[0]+board[index-1]))
                return;
            else{
                ans.push_back(board);
                return;
            } 
        }
        for(auto i=2;i<=num;i++){
            /*剪枝*/
            if(IsUsed[i]||!IsPrime(board[index-1]+i))
                continue;
            board.push_back(i);
            IsUsed[i]=true;
            dfs(ans,board,num,IsUsed,index+1);
            board.pop_back();
            IsUsed[i]=false;
        }
    }
};

int main(int argc,char* argv[]){
    auto x=6;
    vector<vector<int>> ans=Solution().primering(x);
    for(auto& nums:ans){
        for(auto&i:nums)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}