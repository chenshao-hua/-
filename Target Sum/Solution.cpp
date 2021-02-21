/*利用动态规划+二进制位运算*/
#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums){
        if(nums.size()<=1) return false;
        int maxNum=INT_MIN,sum=0;
        for(auto& n:nums){
            maxNum=max(n,maxNum);
            sum+=n;
        }
        int halfsum=sum>>1;
        if(sum%2||maxNum>halfsum) return false;
        if(maxNum==halfsum)
           return true;
        //根据压缩空间后的状态方程为dp[j]=dp[j]||dp[j-nums[i]],
        //相当于每个位置与其前面的第nums[i]个位置的数相与,
        //这与移位之后按位与运算是相同的,dp=dp|(dp<<nums[i])
        bitset<10001> dp(1);//数组中的元素不会超过100,数组的大小不会超过200,所以数组和最大为其的一半
        dp[nums[0]]=1;
        for(int i=1;i<nums.size();i++){
            dp=dp|(dp<<nums[i]);
        }
        return dp[halfsum];
    }
};

int main(int argc,char* argv[]){
    vector<int> nums={1,5,5,10,1};
    cout<<Solution().canPartition(nums)<<endl;
    return 0;
}