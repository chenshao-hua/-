#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans=0,j,temp;
        for(int i=0;i<nums.size();i++){
            temp=0;
            j=i;
            while(j<nums.size()){
                temp+=nums[j];
                if(temp==k){//不能跳出循环,负数可能反转为k,需要遍历完
                    ans++;
                }
                j++;
            }
        }
        return ans;
    }

     int subarraySumOne(vector<int>& nums, int k){
         unordered_map<int,int> dp;
         dp[0]=1;//nums存在元素刚好等于k的情况
         int ans=0,pre=0;
         for(auto& n:nums){
             pre+=n;
             //pre[i]-pre[j-1]=k
             //若dp中存在,key为[当前前缀和-k],说明这个之前出现的前缀和,满足
             //[当前前缀和-该前缀和==k],它出现的次数,累加给count.
             if(dp.count(pre-k)){
                 ans+=dp[pre-k];
             }
             dp[pre]++;//若没有存过,则存入,初始值为1.若存在,则value+1
         }
         return ans;
     }
};

int main(int argc,char* argv[]){
    vector<int> nums={1,-1,0,1,-1,0};//{1,2,3,1,-1,0};
    int k=0;
    cout<<Solution().subarraySum(nums,k)<<endl;
    return 0;
}