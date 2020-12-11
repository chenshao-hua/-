/*
给定一个只包含加、减和乘法的数学表达式,求通过加括号可以得到多少种不同的结果.

示例 1:
Input:"2-1-1"
Ouput:[0,2]

这个样例中,有两种加括号结果:((2-1)-1)=0和(2-(1-1))=2

解题思路:
方法1:
利用分而治之的思想,可以把括号转换为,对于每个运算符号,先执行处理两次的数学表达式,
再处理运算符号.边界情况是,字符串内不存在运算符号.

方法2:
从下到上用动态规划处理.
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution{
public:
    vector<int> diffWaysToCompute(string input){
        vector<int> ways;
        for(auto i=0;i<input.length();i++){
            char c=input[i];
            if(c=='+'||c=='-'||c=='*'){
                /*substr函数第一个参数是位置,第二个参数是个数(若没有,则从该位置到末尾)*/
                vector<int> left=diffWaysToCompute(input.substr(0,i));
                vector<int> right=diffWaysToCompute(input.substr(i+1));
                for(const int& l:left){
                    for(const int& r:right){
                        switch(c){
                            case '+':ways.push_back(l+r);break;
                            case '-':ways.push_back(l-r);break;
                            case '*':ways.push_back(l*r);break;
                        }
                    }
                }
            }
        }

        if(ways.empty())
           ways.push_back(atoi(input.c_str()));//或者stio(input)
        return ways;
    }

    vector<int> diffWays(string input){
        vector<int> data;
        vector<char> ops;
        int num=0;
        char op=' ';
        istringstream ss(input+"+");
        while(ss>>num&&ss>>op){
            data.push_back(num);
            ops.push_back(op);
        }
        int n=data.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>()));
        for(auto i=0;i<n;i++){
            for(auto j=i;j>=0;j--){
                if(i==j){
                    dp[j][i].push_back(data[i]);
                }else{
                    for(auto k=j;k<i;k++){
                        for(auto left:dp[j][k]){
                            for(auto right:dp[k+1][i]){
                                int val=0;
                                switch (ops[k]){
                                    case '+':val=left+right;break;
                                    case '-':val=left-right;break;
                                    case '*':val=left*right;break;
                                }
                                dp[j][i].push_back(val);                         
                            }
                        }
                    }
                }
            }
        }
        return dp[0][n-1];

    }

};

int main(int argc,char* argv[]){
    string input="2-1-1";
    vector<int> ans=Solution().diffWays(input);
    for(auto& i:ans)
       cout<<i<<" ";
    cout<<endl;
    return 0;
}