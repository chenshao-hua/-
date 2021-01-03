/*
判断s字符串是否为字符串t的子序列,包括空字符串.
*/
#include <iostream>
#include <string>

using namespace std;
class Solution{
public:
    bool isSubsequence(string s,string t){
        while(!s.empty()&&!t.empty()){
            if(s[0]==t[0]){
                s=s.substr(1);
            }
            t=t.substr(1);/*或者用t.erase(0,1)即可,删除第一个字符*/
        }
        return s.empty();
    }
};
int main(int argc,char* argv[]){
    string s="abe",t="ahbgcd";
    cout<<Solution().isSubsequence(s,t)<<endl;
    return 0;
}