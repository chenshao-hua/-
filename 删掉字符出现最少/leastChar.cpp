/*
题目描述：
实现删除字符串中出现次数最少的字符，若多个字符出现次数一样，则都删除。
输出删除这些单词后的字符串，字符串中其它字符保持原来的顺序。 

字符串只包含小写英文字母, 不考虑非法输入，输入的字符串长度小于等于20个字节。
删除字符串中出现次数最少的字符后的字符串。

示例1:
Input:abcdd
Output:dd

示例2：
Input:aabbcc
Output:""

解题思路：
方法一：map容器，键存储字符，值存储出现的个数
方法二：用字符-'a'，一维数组存储，数组的值代表出现个数
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
    Solution(string& _S):S(_S){}
    string leastChar(){
        int minfrequency=20,onechar[26]={0};
        for(auto& i:S)
            ++onechar[i-'a'];
        for(int i=0;i<26;i++){
            if(onechar[i])
               minfrequency=min(minfrequency,onechar[i]);
        }
        string result="";
        for(int i=0;i<S.size();i++){
            if(onechar[S[i]-'a']!=minfrequency){
                result+=S[i];
            }            
        }
        return result;
    }
private:
    string S;
};

int main(int argc, char* argv[]){
    string S="aaccbdd";
    Solution solu(S);
    cout<<solu.leastChar()<<endl;
    return 0;
}