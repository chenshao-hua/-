/*
You are given an interger array nums and an integer x.In one operation,you can either remove the leftmost or the rightmost element from the array nums and subtract its value from x.Note that this modifies the array for tuture operations.
Return the minimum number of operation to reduce x to exactly 0 if it's possible,otherwise,return -1.

Example 1:
Input:nums=[1,1,4,2,3]
Output:2
Explanation:The optimal solution is to remove the last two elements to reduce x to zero.

Example 2:
Input:nums=[5,6,7,8,9]
Output:-1

解题思路:
可以利用双指针算法,分别从遍历左边和右边的和,这个题关键的思路是满足删除的元素和等于目标值,而且删除的总次数要达到最小.
此外,需要确定两种特殊情况,若数组的总和刚好等于目标值时,直接得到总次数为数组的个数;
若小于目标值时,返回-1;

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    int minOperations(vector<int>& nums,int x){
        int n=nums.size();
        vector<int> pre(n+1,0),post(n+1,0);
        for(auto i=1;i<=n;i++)
            pre[i]=pre[i-1]+nums[i-1];
        for(auto i=n-1,j=1;j<=n;j++)
            post[j]=post[j-1]+nums[i--];

        if(pre[n]<x)
            return -1;
        if(pre[n]==x)
            return n; 
        int i=0,count=-1,pos=0;    
        while(pre[i]<=x)i++;

        for(;i>=0;i--){
            while(pre[i]+post[pos]<x) pos++;
            if(pre[i]+post[pos]==x){
                if(count==-1||count>i+pos)
                   count=i+pos;
            }
        }
#if 0        
        while(post[pos]<=x)pos++;
        for(;i>=0;i--){
            for(auto j=0;j<=pos;j++){
                if(pre[i]+post[j]==x){
                    if(count==-1){
                        count=i+j;
                        break;
                    }
                    count=min(count,i+j);
                }
            }
        }
#endif
        return count;
    }
};
int main(int argc,char* argv[]){
    vector<int> nums={3,2,20,1,1,3};
    cout<<Solution().minOperations(nums,10)<<endl;
    return 0;
}