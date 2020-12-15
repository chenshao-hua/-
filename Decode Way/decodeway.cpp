/*
建立一位dp数组,长度比输入数组长度多2,全部初始化为1,因为斐波那契数列
的前两项也为1,然后从第三个数开始更新,对应数组的第一个数.对每个数组
首先判断其是否为0,若是将改为dp赋0,若不是,赋上一个dp值,此时相当如加
上了dp[i-1],然后看数组前一位是否存在,如果存在且满足前一位不是0,且
和当前为一起组成的两位数不大于26,则当前dp值加上dp[i-2],至此可以看出
来跟斐波那契数组的递推式一样.
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution{
    public:
    int decodeway(string& str){
        if(str.empty())
           return 0;
        vector<int> dp(str.size()+1,0);
        dp[0]=1;
        for(auto i=1;i<=str.size();i++){
            if(str[i-1]!='0')
               dp[i]+=dp[i-1];
            if(i>=2&&str.substr(i-2,2)>="10"&&str.substr(i-2,2)<="26")
               dp[i]+=dp[i-2];
        }
        return  dp.back();
    }
};

int main(int argc,char* argv[]){
    string str="1016";
    cout<<Solution().decodeway(str)<<endl;
    return 0;
}