/*实现格雷编码序列*/
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution{
public:
    vector<int> generategraycode(const int& n){
        vector<int> ans;
        unordered_set<int> board;/*该容器带count或者find查找函数*/
        bracktrace(n,board,0,ans);
        return ans;
    }
private:
    void bracktrace(const int& n,unordered_set<int>& board,int res,vector<int>& ans){
        if(!board.count(res)){
            board.insert(res);
            ans.push_back(res);
        }
        for(auto i=0;i<n;i++){
            auto index=res;
            if((index&(1<<i))==0){
                index|=(1<<i);
            }else{
                index&=~(1<<i);
            }
            if(board.count(index)) continue;
            bracktrace(n,board,index,ans);
            break;
        }
    }
};
int main(int argc,char* argv[]){
    auto n=4;
    vector<int> ans=Solution().generategraycode(n);
    for(auto& i:ans)
         cout<<i<<" ";
    cout<<endl;
    return 0;
}