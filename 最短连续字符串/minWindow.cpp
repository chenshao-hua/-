/*
题目描述;
给定两个字符串S和T，求S中包含T所有字符的最短连续字符串的长度，同时要求时间复杂度不得超过O(n)。

示例：
输入是两个字符串S和T，输出是一个S字符串的子串。
Input:S="ADOBECDDEBANC",T="ABC"
Output:"BANC"

解题思路;
本题采用滑动窗口进行求解，即两个指针L和R都是从最左端向最右端移动，且L的位置一定在R的左边
或重合。
（1）先遍历T中的字符串，找出各个字符出现的个数，存储在key-value中；
（2）然后遍历S中字符串，每遇到一个T中的字符，则把对应的个数进行减1，如果这个字符对应的值大于
或等于0，则count++；
（3）若count第一次等于T.size()时，则第一次选中包含所有指定字符的区间，设置为暂时最短的字符串。
，然后右移滑动窗口，进行加1，如果右移前最左边的L字符正是字符串T的一个字符，那么count就需要进行
减1；
*/

#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution{
public:
    Solution(string& _S,string& _T):S(_S),T(_T){}
    string minWindow(){
        if(T.size()>S.size()){
            cout<<"不满足条件..."<<endl;
            return "";
        }
        map<char,int> countchar;

        /*先统计T中的字符情况*/
        for(int i=0;i<T.size();i++){
            if(countchar.find(T[i])!=countchar.end())
                countchar[T[i]]++;
            else
                countchar[T[i]]=1;          
        }

        int L=0,R=0,count=0,minsize=S.size()+1;
        string mindow="";
        /*移动滑动窗口，不断更改统计数据*/
        for(;R<S.size();R++){
            if(countchar.find(S[R])!=countchar.end()){
                countchar[S[R]]--;/*每遇到T中的一个字符，则进行减1*/
                if(countchar[S[R]]>=0)
                    count++;/*T中至少存在该字符*/
                /*当前滑动窗口已经包含T中的所有字符*/
                while(count==T.size()){
                    /*若此窗口边界小于最小长度，更新最小长度，并获取当前区间的字符串*/
                    if(R-L+1<minsize){
                        minsize=R-L+1;
                        mindow=S.substr(L,minsize);
                    }
                    /*若countchar的最左边字符正好是S中的一个字符*/
                    if(countchar.find(S[L])!=countchar.end()){
                        countchar[S[L]]++;
                        if(countchar[S[L]]>0)
                            count--;
                    }
                    /*尝试右移，获取最短的字符串*/
                    L++;
                }
            }
        }
        return mindow;
    }
private:
    string S,T;
};

int main(int argc,char* argv[]){
    string S="ADOBECDDEBANC",T="ABC";
    Solution solu(S,T);
    printf("%s\n",solu.minWindow().c_str());
    return 0;
}