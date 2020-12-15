/*
给定一个包含[0,n]中n个数的数组nums,找出[0,n]这个范围内没有出现在数组中
的那个数字.

示例 1:
Input:nums=[3,0,1]
Output:2

示例 2:
Input:nums=[0,1]
Output:2
因为有2个数字,所有数字都在[0,2]之间内.

示例 3:
Input:nums=[9,6,4,2,3,1,5,7]
Output:8

解题思路:
方法1
利用等差数列求和公式求出总和,然后与数组的总和做差.

方法2
位运算
通过异或进行,a^a=0,a^0=a
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int missingnumber(vector<int>& nums){
        if(nums.empty())
           return -1;
        auto sum=nums.size()*(nums.size()+1)/2;
        for(auto& i:nums)
           sum-=i;
        return sum;
    }

    int missingornumber(vector<int>& nums){
        if(nums.empty())
           return -1;
        auto number=nums.size();
        for(auto i=0;i<nums.size();i++)
           number^=i^nums[i];
        return number;
    }
};
int main(int argc,char* argv[]){
    vector<int> nums={9,6,4,2,3,1,5,0,7};
    cout<<Solution().missingnumber(nums)<<endl;
    return 0;
}