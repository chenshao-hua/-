/*
Given a list of daily temperatures T,return a list such that,for each day in the input,tells
 you how many days you would have to wait until a warmer temperature.If there is no future 
 day for which this is possible,put 0 instead.
For example,given the list of temperatures T=[73,74,75,71,69,72,76,73],your output should 
be [1,1,4,2,1,1,0,0].
Note:
The length of temperatures will be in the range [1,30000].Each temperature will be an 
integer in the range[30,100].

Example 1:
Input:[73,74,75,71,69,72,76,73]
Output:[1,1,4,2,1,1,0,0]

题目大意:
给定每天的温度,求对于每一天需要等几天才可以等到更暖和的一天.如果该天之后不存在更暖和的天气,则记为0.

解题思路:
这道题比较理想的算法是利用单调栈,可以维持一个单调递减的栈,表示每天的温度:为了方便计算天数差,这里存放位置(即日期)
而非温度本身.从左向右遍历温度数组,对于每个日期p,如果p的温度比栈顶存储的位置q的温度高,则我们取出q,并且记录q需要
等待的天数p-q;我们重复这一过程,直到p的温度小于等于栈顶存储位置的温度(或空栈)时,将p插入栈顶,然后考虑下一天.
在这个过程中,栈内数组永远保持单调递减,避免了使用排序进行比较.最后栈内剩余一些日期,则说明它们之后都没有出现更
暖和的日期.

*/
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution{
public:
    vector<int> dailyTemperature(vector<int>& temperatures){
        int n=temperatures.size();
        vector<int> ans(n);
        stack<int> index;
        for(int i=0;i<n;i++){
            while(!index.empty()){
                int pre_index=index.top();
                if(temperatures[i]<=temperatures[pre_index])
                    break;
                index.pop();
                ans[pre_index]=i-pre_index;
            }
            index.push(i);
        }
        return ans;
    }
};
int main(int argc,char* argv[]){
    vector<int> tempratures={73,74,75,71,69,72,76,73};
    vector<int> ans=Solution().dailyTemperature(tempratures);
    for_each(ans.begin(),ans.end(),[&](const int& num){
        cout<<num<<" ";
    });
    cout<<endl;
    return 0;
}