#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution{
public:
    int longestArithmeticSeqLength(vector<int>& A){
        int ans=0,n=A.size(),diff=0;
        vector<vector<int>> dp(n,vector<int>(2000));
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                diff=A[i]-A[j]+1000;
                dp[i][diff]=dp[j][diff]+1;
                ans=max(ans,dp[i][diff]);
            }
        }
        return ans+1;
    }

    int longestArithmeticSeqLengthOne(vector<int>& A){
        int ans=0,n=A.size(),diff=0;
        unordered_map<int,int> board;
        vector<vector<int>> dp(n,vector<int>(n,2));//至少为2
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                diff=2*A[i]-A[j];
                if(board.count(diff)) //判断前一个值是否存在.
                    dp[i][j]=dp[board[diff]][i]+1;//更新当前个数
                ans=max(dp[i][j],ans);
            }
            board[A[i]]=i;
        }
        return ans;
    }
};

int main(int argc,char* argv[]){
    vector<int> A={9,4,7,2,10};
    cout<<Solution().longestArithmeticSeqLength(A)<<endl;
    cout<<Solution().longestArithmeticSeqLengthOne(A)<<endl;
    return 0;
}