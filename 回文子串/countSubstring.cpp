/*
题目描述：
给定一个字符串，计算这个字符串中有多少个回文子串。具体不同开始位置或结束位置的子串，即使
是由相同的字符组成，也会被视为不同的子串。

示例：
Input:"abc"
Output:3
其中，三个回文子串:"a","b","c"

Input:"aaa"
Output:6
其中，六个回文子串:"a","a","a","aa","aa","aaa"

提示：输入的字符串长度不会超过1000

解题思路：
这道题使用冬天规划是比较合理的方法：
1.状态：dp[i][j]表示字符串s在[i,j]区间的子串是否是一个回文串；
2.状态转移：
（1）当只有一个字符时，比如a自然是一个回文子串；
（2）当有两个字符时，若时相等的，比如aa，也是一个回文子串；
（3）当有三个以及以上字符的时候，比如ababa这个字符记作子串1，把两边的a去掉，也就是bab记作子串2，可以
看出只要子串2，可以用看做只要子串2为一个回文串，那么左右多了一个a的子串1必定也是回文串，那么左右各多了
一个a的子串1必定也是回文串。所有当s[i]=s[j]时，自然要看dp[i+1][j-1]是不是一个回文串。
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    Solution(string& _s):s(_s){}
    int countSubstring(){
        vector<vector<bool>> dp(s.size(),vector<bool>(s.size()));
        int count=0;

        for(int j=0;j<s.size();j++){
            for(int i=0;i<=j;i++){
                if(s[i]==s[j]&&(j-i<2||dp[i+1][j-1])){
                    dp[i][j]=true;
                    count++;
                }
            }
        }

        return count;
    }
private:
    string s;
};

int main(int argc,char* argv[]){
    string s="abcdedc";
    Solution solu(s);
    cout<<solu.countSubstring()<<endl;
    return 0;
}