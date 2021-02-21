
Given an array of integers nums and an integer k,return the total number of continuous 
subarrays whose sum equals to k.

Example 1:
Input:nums=[1,1,1],k=2
Output:2

Example 2:
Input:nums=[1,2,3],k=3
Output:2
 
Example 3:
Input:nums=[1,-1,0],k=0
Output:3
 
Constraints:
(1)1<=nums.length<=2*10^4;
(2)-1000<=nums[i]<=1000;
(3)-10^7<=k<=10^7;

题目大意:给定一个整数数组nums和一个整数k,你需要找到该数组中和为k的连续的子数组的个数.

解题思路:

方法1:
双层遍历,需要注意第二层需要遍历完,因为存在负数和零,可以反转,超时.

方法2:
前缀和+哈希优化,求nums[i]的前i项和,存储在pre[i]中.即可:pre[i]=pre[i-1]+nums[i];假如存在j->i时,子数组的
和为k,则可以转换为,pre[i]=pre[j-1]+nums[j]+...+nums[i],则pre[i]=pre[j-1]+k;简单的移植可以得到满足的
条件为pre[j-1]=pre[i]-k.因此在考虑以i为结尾的和为k的连续子数组个数时,只需要统计有多少个前缀和为为pre[i]-k的
pre[j]即可,j必须在i之前.
然后建立map,key为pre[i],value为出现的次数,从左往右更新map,那么以i结尾的答案map[pre[i]-k];最后的答案即
为所有下标结尾的和为k的子数组个数之和.初始化key值为0,对应value为1,表示满足条件进行+1.存在pre[i]-k=0的情况.
其实不用关注那两项pre前缀和之差等于k,只需要关注等于k的前缀和之差出现的次数x.就知道有x个子数组求和等于k.