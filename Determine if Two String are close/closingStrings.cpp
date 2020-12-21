/*
Two strings are considered close if you can attain one from the other using the following operaitons:
（1）Operation 1:Swap any two existing characters.
For example,abcde->aecdb
（2）Operation 2:
Transform every occurrence of one existing character into another existing character,and do the same with the other character.
For example,aacabb->bbcbaa (all a's turn into b's, and all b's turn into a's)

You can use the operations on either string as many times as necessary.
Given two strings,words and word2,return true if word1 and word2 are close,and false 
otherwise.

Example 1:
Input:word1="abc",word2="bca"
Output:true
Explanation:You can attain word2 from word1 in 2 operations.
Apply Operation 1:"abc"->"acb"
Apply Operation 1:"acb"->"bca"

Example 2:
Input:word1="cabbba",word2="abbccc"
Output:true
Explanation: You can attain word2 from word1 in 3 operations.
Apply Operation 1:"cabbba" -> "caabbb"
Apply Operation 2:"caabbb" -> "baaccc"
Apply Operation 2:"baaccc" -> "abbccc"

解题思路:
这道题判断两个字符串是否相似,根据两个方面:字符串的次数相同,只是交换顺序;
字符在字母表中出现的次数.
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

class Solution{
    public:
    bool closeStrings(string word1,string word2){
        memset(str1,0,sizeof(str1));
        memset(str2,0,sizeof(str2));
        memset(ans,0,sizeof(ans));
        for(char c:word1)
           str1[c-'a']+=1;
        for(char c:word2)
           str2[c-'a']+=1;
        
        for(auto i=0;i<26;i++)
           ans[i]=(str1[i]>0)-(str2[i]>0);

        sort(str1,str1+26);
        sort(str2,str2+26);  
        for(auto i=0;i<26;i++){
            if(ans[i]!=0||str1[i]!=str2[i])
               return false;
        }
        return true;
    }
private:
    int str1[30],str2[30],ans[30];
};
int main(int argc,char* argv[]){
    string str1="cabbba",str2="aabbcc";
    cout<<Solution().closeStrings(str1,str2)<<endl;
    return 0;
}