/*
字符串中用"%20"替代空格

示例 1：
Input:str="I like China."
Output:"I%20like%20China."

若将多个连续的空格减少到1个再替换,如何实现？
只需要设置一个flag加入判断条件即可
*/
#include <iostream>

using namespace std;

class Solution{
public:
    string replaceblank(const string& str){
        string ans="";
        for(auto& i:str){
            if(i==' '){
                ans+="%20";
            }else{
                ans+=i;
            }
        }
        return ans;
    }
    string replacemultiblank(const string& str){
        string ans="";
        bool flag=false;
        for(auto& i:str){
            if(i==' '&&!flag){
                ans+="%20";
                flag=true;
            }else if(i!=' '){
                ans+=i;
                flag=false;
            }
        }
        return ans;
    }
};
int main(int argc,char* argv[]){
    string str="I  like China.";//getline(cin,str)可以从键盘输入一连串带空格的字符串
    cout<<Solution().replaceblank(str)<<endl;
    cout<<Solution().replacemultiblank(str)<<endl;
    return 0;
}