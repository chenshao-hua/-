#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    int maxUncrossedLines(vector<int>& A,vector<int>& B){
        int m=A.size(),n=B.size();
        
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;++i){
            for(int j=1;j<=n;++j){
                if(A[i-1]==B[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};
int main(int argc,char* argv[]){
    vector<int> A={1,3,7,1,7,5},B={1,9,2,5,1};
    cout<<Solution().maxUncrossedLines(A,B)<<endl;
    return 0;
}