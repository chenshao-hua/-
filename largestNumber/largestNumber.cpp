/*
给定一组非负整数nums,重新排列它们每个数字的顺序（每个数字不可拆分）使之
组成一个最大的整数.

注意:输出结果可能非常大,所以你需要返回一个字符串而不是整数.

 
示例 1:
Input:nums=[10,2]
Output:"210"

示例 2:
Input:nums=[3,30,34,5,9]
Output:"9534330"

示例 3:
Input:nums = [1]
Output:"1"

提示:
1<=nums.length<=100
0<=nums[i]<=109

解题思路:
（1）将原数值数组转为字符串数组，方便拼接和比较;
（2）将字符串数组排序;
（3）从头到尾拼接结果;
字符串排序需要注意一点,当首位相等的时候,需要考虑到后面的位数,因此,通过比较
两个字符串前后进行相加进行比较,得出较大者.
*/
#include <iostream>
#include <vector>
#include <algorithm>/*generate、sort*/
#include <string>/*to_string函数*/
#include <numeric>/*accumulate函数*/

using namespace std;

class Solution{
public:
    string largestNumber(vector<int>& nums){
        vector<string> ans(nums.size());
        auto it=nums.begin();
        /*转换成字符串数组*/
        generate(ans.begin(),ans.end(),[&it]{
            return to_string(*(it++));//*(it++)等价于*it++,先it指向的值,再进行指针加1
        });

        /*排序*/
        sort(ans.begin(),ans.end(),[](auto& a,auto& b){
            return a+b>b+a;
        });

        /*拼接*/
        string result=accumulate(ans.begin(),ans.end(),string(""),[](auto& a,auto& b){
            return a+b;
        });
        return result;
    }
};
int main(int argc,char* argv[]){
    vector<int> nums={3,30,34,5,9};
    cout<<Solution().largestNumber(nums)<<endl;
    return 0;
}