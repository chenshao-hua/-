/*

Given a pattern and a string str,find if str follows the same pattern.
Here follow means a full match,such that there is a bijection a letter in pattern and a 
non-tmpty word in str.

Examples:

pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.

Note:
You may assume pattern contains only lowercase letters ,and str contains lowercase letters 
sepatated by a single space.

题目大意:
给定一个模板字符串和一个str字符串,判断str字符串是否遵循模板字符串？

解题思路:
方法1:
利用hashmap进行存储,key存储单个字符,value存储str其中一个.注意遍历过程中需要剔除空格.可以使用istringstream
分割字符串.注意需要判断key值是否存在,存在则需要判断value值是否相等;若没有还需判断是否已经存在value.

方法2
算法优化,可以直接用set容器或者map容器存储pattern的单个字符和strs数组中的对应的位置的字符串,在insert过程
中返回pair<iterator,bool>,可以根据interator判断value是否相等

方法3
不用map的insert,
*/
#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <cstring>
#include <set>

using namespace std;

class Solution{
public:
    bool wordPattern(string pattern,string str){
        //可以直接枚举str字符串剔除空格
        istringstream is(str);//剔除空格
        vector<string> strs;
        string s;
        while(is>>s){
            strs.push_back(s);
        }
        if(strs.size()!=pattern.size()) return false;//不相等直接返回
        map<char,string> ans;
        set<string> temp;
        int i=0;
        for(auto& j:strs){
            if(ans.count(pattern[i])){
                if(ans[pattern[i]]!=j)//字符已经存在,字符串不等
                   return false;
            }else{
                if(temp.count(j))//字符不同在插入之前需要判断字符串是否已经存在
                   return false;
                temp.insert(j);
                ans.insert({pattern[i],j});//make_pair(pattern[i],j)
            }
            i++;
        }
        return true;
    }
    bool wordPatternOne(string pattern,string str){
        vector<string> strs;
        string tmp;
        tmp.clear();
        int pos=0;
        for(int i=0;i<str.size();++i){
            if(str[i]==' '){
                strs.push_back(str.substr(i-pos,pos));//pos是substring的长度
                pos=0;
            }else{
               pos++;  
            }         
        }
        strs.push_back(str.substr(str.size()-pos,pos));
        
        if(pattern.size()!=strs.size()) 
            return false;

        map<string,int> ans;
        map<char,int> res;
        for(int i=0;i<strs.size();++i){ 
            if(res.insert({pattern[i],i}).first->second!=ans.insert({strs[i],i}).first->second){
                return false;
            }
        }
        return true;
    }
    bool wordPatternTwo(string pattern,string str){
        stringstream ss(str);
        map<string,char> ans;
        map<char,string> res;
        string s;
        for(auto& c:pattern){
            if(!(ss>>s)||(res.count(c)==1&&res[c]!=s)||(ans.count(s)==1&&ans[s]!=c)){
                return false;
            }
            ans[s]=c;
            res[c]=s;
        }
        return (ss>>s)?false:true;
    }
};

int main(int argc,char* argv[]){
    string pattern="abc", str = "b c a";
    //cout<<Solution().wordPattern(pattern,str)<<endl;
    cout<<Solution().wordPatternTwo(pattern,str)<<endl;
    return 0;
}