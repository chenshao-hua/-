#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
class Solution{
 public:
    int minDistanc(string A,string B){
        int lenA=A.length();
        int lenB=B.length();
        vector<vector<int>> dp(lenA+1,vector<int>(lenB+1,0));

        for(int i=1;i<lenA+1;i++)
            dp[i][0]=i;
        for(int j=1;j<lenB+1;j++)
            dp[0][j]=j;
        
        for(int i=1;i<lenA+1;i++){
            for(int j=1;j<lenB+1;j++){
                if(A[i-1]==B[j-1])
                    dp[i][j]=dp[i-1][j-1];
                else 
                    dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
            }
        }
        return dp[lenA][lenB];
    }
};

int main(int argc,char* argv[]){
    Solution temp;
    cout<<temp.minDistanc("chen","zhu")<<endl;
    return 0;
}