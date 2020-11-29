/*
题目描述:
给定一个经过编码的字符串,返回它解码后的字符串.
编码规则为:k[encoded_string],表示其中方括号内部的encoded_string正好重复
k次.注意k保证为正整数.

示例 1:
Input:s="3[a]2[bc]"
Output:"aaabcbc"

示例 2:
Input:s="3[a2[c]]"
Output:"accaccacc"

示例 3:
Input:s="2[abc]3[cd]ef"
Output:"abcabccdcdcdef"

解题思路:
这道题是典型的栈算法,构建两个栈,数字存放在数字栈,字符串存放在字符串栈,遇到
右括号时候弹出一个数字栈,字母栈弹到左括号为止.
*/
#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution{
private:
    string s;

public:
    Solution(string& _s):s(_s){}
    string decodeString(){
        string result="";
        auto num=0;
        stack<int> nums;
        stack<string> strs;
        for(auto letter=0;letter<s.size();letter++){
            if(s[letter]>='0'&&s[letter]<='9')
                num=num*10+s[letter]-'0';/*字符0代表的是48*/
            else if(s[letter]=='['){             
                nums.push(num);
                num=0;
                strs.push(result);
                result="";
            }else if(s[letter]==']'){
                int n=nums.top();
                nums.pop();
                for(auto i=1;i<=n;++i)
                   strs.top()+=result;
                result=strs.top();
                strs.pop();
            }else
                result+=s[letter]; /*a~z或A~Z*/
        }
        return result;
    }
};

int main(int argc,char* argv[]){
    string s="3[a]2[bc]";
    string result=Solution(s).decodeString();
    cout<<result<<endl;
    //printf("%s",result.c_str());
    return 0;
}