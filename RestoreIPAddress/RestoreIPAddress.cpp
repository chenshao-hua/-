/*求字符串中所有可能的IP组合*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution{
private:
    vector<string> ans;
    string s;
    int  n;

public:
    vector<string> restoreIPAddress(string& _s){
        if(_s.size()<4||_s.size()>12)
            return ans;
        s=_s;
        n=_s.size();
        dfs(0,0,"");
        return ans;
    }

private:
    void dfs(int index,int depth,string path){
        if(depth==4){
            path.pop_back();
            ans.push_back(path);
            return;
        }
        int Min=max(index+1,n-(3-depth)*3);
        int Max=min(index+3,n-(3-depth));
        for(auto i=Min;i<=Max;i++){
            string split=s.substr(index,i-index);
            auto len=split.size();
            if(len>1&&split[0]=='0')
               break;
            if(stoi(split)<=255){
                dfs(i,depth+1,path+(split+'.'));
            }
        }
    }
};

int main(int argc,char* argv[]){
    string s="22522511135";
    vector<string> ans=Solution().restoreIPAddress(s);
    for(auto& i:ans)
       cout<<i<<endl; 
    return 0;
}