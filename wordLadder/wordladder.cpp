/*
给定一个起始字符串和一个终止字符串,以及一个单词表,求是否可以将起始字符串酶促改一个字符,
直到改成终止字符串,且所有中间的修改过程表示的字符串都可以在单词表里面找到.若存在,输出
需要修改次数最少的所有更改方式.

示例 1
Input:beginWord="hit",endWord="cog",wordList=["hot","dot","lot","log","cog"]
Output:[["hit","hot","dog","cog"],
        ["hit","hot",log","cog"]]

解题思路:
我们可以把起始字符串,终止字符串,以及单词表里面所有的字符串想象成节点.若两个字符串只有一个字符不同,
那么它们相连.因为题目需要输出修改次数最少的所有修改方式,因此可以使用广度优先搜索,求得起始节点到
终止节点的最短距离.
同时还使用一个小技巧:并不是直接从起始节点进行广度优先搜索,直到找到终止节点为止:而是从起始节点和
终止节点分别进行广度优先搜索,每次只延展当前层节点数最少的那一端,这样可以减少搜索的总结点数.举例来说,
假设最短距离为4,如果只从一端搜索4层,总遍历节点数最多是1+2+4+8+16=31;而如果从两端各搜索两层,总
遍历节点数最多只有2x(1+2+4)=14;
在搜索结束后,还需要通过回溯法来重建所有可能的路径.
*/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution{
public:
    vector<vector<string>> findLadders(string beginWord,string endWord,vector<string>& wordList){
        vector<vector<string>> ans;
        unordered_set<string> dict;
        for(const auto&w:wordList)
            dict.insert(w);
        if(!dict.count(endWord))/*set容器查找,返回0或者1*/
            return ans;
        dict.erase(beginWord);
        dict.erase(endWord);
        unordered_set<string> q1{beginWord},q2{endWord};
        unordered_map<string,vector<string>> next;
        bool reversed=false,found=false;
        /*广度优先遍历*/
        while(!q1.empty()){
            unordered_set<string> q;
            for(const auto&w:q1){
                string s=w;
                for(size_t i=0;i<s.size();i++){
                    char ch=s[i];
                    for(size_t j=0;j<26;j++){
                        s[i]=j+'a';
                        if(q2.count(s)){
                            reversed?next[s].push_back(w):next[w].push_back(s);
                            found=true;
                        }
                        if(dict.count(s)){
                            reversed?next[s].push_back(w):next[w].push_back(s);
                            cout<<s<<endl;
                            q.insert(s);
                        }
                    }
                    s[i]=ch;
                }
            }               
            if(found){
                break;
            } 
            for(const auto& w:q){
                dict.erase(w);
            }
            if(q.size()<=q2.size()){
                q1=q;
            }else{
                reversed=!reversed;
                q1=q2;
                q2=q;
            }
        }
        /*回溯符合条件的路径*/
        if(found){
            vector<string> path={beginWord};
            backtrack(beginWord,endWord,next,path,ans);
        }
        return ans;
    }

private:
    void backtrack(const string& src,const string& dst,unordered_map<string,
    vector<string>>&next,vector<string>&path,vector<vector<string>>& ans){
        if(src==dst){
            ans.push_back(path);
            return;
        }
        for(const auto&s:next[src]){
            path.push_back(s);
            backtrack(s,dst,next,path,ans);
            path.pop_back();
        }
    }
};

int main(int argc,char* argv[]){
    string beginWord="hit",endWord="cog";
    vector<string> wordList={"hot","dot","lot","log","cog"};
    vector<vector<string>> ans=Solution().findLadders(beginWord,endWord,wordList);
    for_each(ans.begin(),ans.end(),[](vector<string>& res){
        cout<<"[ ";
        for(const auto&i:res)
            cout<<i<<" ";
        cout<<"]";
    });
    return 0;
}