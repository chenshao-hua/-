#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    Solution(const int& _num):num(_num){}
    int numSquare(){
        vector<int> dp(num+1);/*初始num+1个*/
        for(auto i=1;i<=num;i++){
            dp[i]=i;/*最坏的情况是每次+1*/
            for(auto j=1;i-j*j>=0;j++){
                dp[i]=min(dp[i],dp[i-j*j]+1);/*状态转移方程*/
            }
        }
        return dp[num];
    }
private:
    const int num;
};
int main(int argc,char* argv[]){
    auto num=10;
    cout<<Solution(num).numSquare()<<endl;
    return 0;
}