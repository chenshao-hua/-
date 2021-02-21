#include <iostream>
#include <vector>
#include <cstring>
#include <cctype> //isupper判断是否为大写字母或者c>='A'&&c<='Z'

using namespace std;

class Solution {
public:
    //双指针
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans;
        for(auto& query:queries){ 
            ans.push_back(isMatch(query,pattern));
        }
        return ans;
    }
    bool isMatch(string query,string pattern){
        int ql=0,qr=query.size()-1;
        int pl=0,pr=pattern.size()-1,n=0;
        while(ql<=qr){ 
            printf("ql:%d qr:%d pl:%d pr:%d\n",ql,qr,pl,pr);
            if(query[ql]==pattern[pl]){
                ++pl;
                if(pl<=pr+1)
                   n++;//避免下面进行n累加1.
            }else if(isupper(query[ql])){
                return false;
            }
            ++ql;
            if(query[qr]==pattern[pr]){               
                --pr;
                if(pl<=pr+1)
                   n++;//避免下面进行n累加1.
            }else if(isupper(query[qr])){
                return false;
            }
            --qr;   
        }
        cout<<n<<endl;
        return n==pattern.size();
    }

    //直接枚举
    vector<bool> camelMatchOne(vector<string>& queries, string pattern) {
        vector<bool> res;
        for(auto& query:queries){
            int i=0,flag=true;
            for(auto& q:query){
                if(pattern[i]==q){
                    i++;
                }else if(isupper(q)){
                    flag=false;
                }
            }
            res.push_back(flag&&i==pattern.size());
        }
        return res;
    }
};

int main(int argc,char* argv[]){
    vector<string> queries={"FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"};
    string pattern="FB";
    // vector<string> queries={"MifeQvzphNrv","MieQxvrvhNrv","MhieQovhNryv"};
    // string pattern="MieQvhNrv";
    // vector<string> queries={"CompetitiveProgramming","CounterPick","ControlPanel"};
    // string pattern="CooP";
    vector<bool> ans=Solution().camelMatch(queries,pattern);
    for(bool an:ans){
        printf("%d ",an);
    }
    return 0;
}