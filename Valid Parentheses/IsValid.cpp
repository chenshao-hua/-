/*
括号是否有效？
通过栈可以实现
*/

#include <iostream>
#include <stack>

using namespace std;

class Solution{
public:
    bool IsValid(string str){
        if(str.empty()){
            return true;
        }
        stack<char> ans;
        for(auto& i:str){
            if(i=='['||i=='('||i=='{'){
                ans.push(i);
            }else if((i==']'&&ans.size()>0&&ans.top()=='[')
            ||(i==')'&&ans.size()>0&&ans.top()=='(')
            ||(i=='}'&&ans.size()>0&&ans.top()=='{')){
                ans.pop();
            }else{
                return false;
            }
        }
        return ans.size()==0;
    }
};

int main(int argc,char* argv[]){
    string str="([])";
    cout<<Solution().IsValid(str)<<endl;
    return 0;
}