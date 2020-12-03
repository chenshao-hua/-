/*
通过string类实现字符串反转,';'是作为分割对象

示例 :
Input:"We;Come from;China"
Output:"eW;morf emoC;anihC"

*/
#include <iostream>
#include <string>
//#include <sstream> /*实现字符串流的输入、输出,省掉控制台*/
#include <algorithm>

using namespace std;

class Solution{
public:
    string reverseList(string& str){
        int start=0,end,len;
        string result="",temp;
        for(;;){
            end=str.find(';',start);/*返回所在的位置,若没有则-1*/
            if(end==-1){
                len=str.length()-start;
                temp=str.substr(start,len);/*左闭右开*/
                reverse(temp.begin(),temp.end());/*反转当前字符串*/
                result+=temp;
                break;
            }else{
                /*存在*/
                len=end-start;
                temp=str.substr(start,len);/*左闭右开,此时不包含';'*/
                reverse(temp.begin(),temp.end());
                result+=temp+';';
                start=end+1;
            }
        }
        return result;
    }
};
int main(int argc,char* argv[]){
    string str="We;Come from;China";
    cout<<Solution().reverseList(str)<<endl;
    return 0;
}