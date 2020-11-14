/*
给你一个字符串s,请你拆分该字符串,并返回拆分后唯一子字符串的最大数目.字符串s拆分
后可以得到若干 非空子字符串,这些子字符串连接后应当能够还原为原字符串.但是拆分出来
的每个子字符串都必须是唯一的.
注意:子字符串是字符串中的一个连续字符序列.

示例 1：
Input:s="ababccc"
Output:5
解释:一种最大拆分方法为['a','b','ab','c','cc'].像['a','b','a','b','c','cc']
这样拆分不满足题目要求,因为其中的'a'和'b'都出现了不止一次.

示例 2：
Input:s="aba"
Output:2
解释:一种最大拆分方法为['a','ba']

示例 3：
Input:s="aa"
Output:1
解释:无法进一步拆分字符串.
 

提示：
（1）1<=s.length<=16
（2）s仅包含小写英文字母

解题思路:
对于长度为n的字符串,有n−1个拆分点.从左到右遍历字符串,对于每个拆分点,如果在
此拆分之后,新得到的一个非空子字符串,即拆分点左侧的最后一个被拆分出的非空子字
符串,与之前拆分出的非空子字符串都不相同,则当前的拆分点可以进行拆分,然后继续
对剩下的部分(即拆分点右侧的部分)进行拆分.
（1）回溯(深度优先遍历)；
（2）使用一个哈希验证是否已有重复子串,这里使用set容器,insert的返回值是pair对,第一个
    是当前的迭代器,第二个是bool类型；
（3）判断剩余字符长度和已有答案,进行剪枝；
*/


#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;


class Solution{
public:
    Solution(string& _s):S(_s),count(0){}
    void dfs(string& s,int x,int n){
        if(x==n){
            bool flag=true;
            hash.clear();
            for(string& w:words){
                if(hash.insert(w).second==false)
                   flag=false;
            }
            if(flag)
               count=max(count,(int)words.size());
        }else{
            string cur="";
            for(int i=x;i<n;i++){
                cur+=s[i];/*单个字符*/
                words.push_back(cur);
                dfs(s,i+1,n);
                words.pop_back();
            }
        }
    }
    int maxUniqueSplit(){
        dfs(S,0,S.size());
        return count;
    }  
private:
    string S;
    set<string> hash;
    vector<string> words;
    int count;
};

int main(int argc,char* argv[]){
    string S="wwwzfvedwfvhsww";
    Solution solu(S);
    cout<<solu.maxUniqueSplit()<<endl;
    return 0;
}
