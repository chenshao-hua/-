/*
验证给定的字符串是否为有效的前缀二叉树序列.
需要用到strtok这是c语言的函数.char*类型,printf这是c的语法,不能简单string输出
c++分割字符串还可以直接枚举也可以.
方法二:
stack的思想.
先序遍历中'#'个数总是比数字个数大1个,而且以#结尾.因此在先序遍历字符串数组中去除最后一个字符'#',
则节点个数与'#'个数应该相匹配.任何时候不能出现'#'个数大于节点的个数.设置count统计个数,在遇到数
字时进行+1,遇到'#'时-1.如果此时小于0则返回false,执行完成后判断最后一个字符是否为'#‘.
*/
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <stack>

using namespace std;
class Solution{
public:
    bool isValidSerialization(string preorders){
        /*分割字符串*/
        char *pre=new char[preorders.size()+1];
        strcpy_s(pre,preorders.size()+1,preorders.c_str());/*或者strncpy(pre,orders.c_str(),orders.size()+1)*/
        char* str=strtok(pre,",");
        vector<string> ans;/*或者vector<char>,下面的push_back(*str)*/
        while(str!=nullptr){
            ans.push_back(str);
            str=strtok(NULL,",");
        }
        int dif=1;
        /*入度+2,出度-1*/
        for(auto& c:ans){
            dif--;
            if(dif<0)  return false;
            if(c!="#"){
                dif+=2;
            }
        }
        return dif==0;
    }
    bool isValid(string preorder){
        /*
        vector<string> strs;
        int count=0;
        for(auto& s:preorder){
            in+=s;
            count++;
            if(s==","){
                strs.push_back(in);
                in="";
            }else{
                in+=s;
            }
            if(count==preorder.size()){
                str.push_back(in);//输出最后一个
            }
        }
        */
        stringstream s(preorder);
        vector<string> strs;
        string in;
        while(getline(s,in,'#')){
            strs.emplace_back(in);
        }
        stack<string> res;
        for(auto& str:strs){
            if(str=="#"){
                if(res.empty()){
                    return false;
                }
                res.pop();
            }else{
                res.push(str);
            }
        }
        return strs.back()=="#"&&res.empty();
    }
};

int main(int argc,char* argv[]){
    string preorders="9,#,92,#,#";//"9,3,4,#,#,1,#,#,2,#,6,#,#";
    /*
    string in;
    for(int i=0;i<=preorders.size();++i){
        if(preorders[i]==','||i==preorders.size()){       
            cout<<i<<" "<<in<<endl;
            in="";
        }else{
           in+=preorders[i]; 
        }                  
    }
    */
    //cout<<Solution().isValidSerialization(preorders)<<endl;
    return 0;
}