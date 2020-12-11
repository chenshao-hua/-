/*
实现n对括号的有效组合
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution{
public:
    vector<string> generateparenthese(const int& n){
        if(n==0)
           return {};
        vector<string> ans;
        /*pair<括号字符串, pair<左括号剩余,右括号剩余>*/
        queue<pair<string,pair<int,int>>> board;
        board.push({"",{n,n}});
        while(!board.empty()){
            auto top=board.front();
            board.pop();
            string str=top.first;
            int left=top.second.first,right=top.second.second;
            if(left==0&&right==0){
                ans.push_back(str);
            }
            if(left>0)
               board.push({str+"(",{left-1,right}});
            if(right>0&&right>left)
               board.push({str+")",{left,right-1}});
        }
        return ans;
    }
};

int main(int argc,char* argv[]){
    auto n=3;
    vector<string> ans=Solution().generateparenthese(n);
    for(auto& res:ans)
       cout<<res<<" ";
    cout<<endl;
    return 0;
}