Description

In the computer world,use restricted resource you have to generate maximum benefit is what we always
want to pursue.

For now,suppose you are a dominator of m 0s and n 1s respectively.On the other hand,there is an array
with strings consisting of only 0s and 1s.

You are given an array of binary strings strs and two integers m and n.

Return the size of the largest subset of strs such that there are at most m 0's and n 1's in the 
subset.

A set x is a subset of a set y if all elements of x are also elements of y.


Note:

1.The given numbers of 0s and 1s will both not exceed 100;
2.The size of given string array won't exceed 600.

Example 1:
Input:strs=["10","0001","111001","1","0"],m=5,n=3

Output:4

Explanation: The largest subset with at most 5 0's and 3 1's is {"10","0001","1","0"}, so the
answer is 4.Other valid but smaller subsets include {"0001","1"} and {"10","1","0"}.
{"111001"} is an invalid subset because it contains 4 1's, greater than the maximum of 3.

Example 2:

Input: strs=["10","0","1"], m=1, n=1

Output: 2

Explanation: The largest subset is {"0","1"}, so the answer is 2.

Example 3:

Input:strs=["111","1000","1000","1000"],m=9,n=3

Output:3

Explanation: The largest subset is {"1000","1000","1000"}, so the answer is 3.

题目大意:

给你一个二进制字符串数组strs和两个整数m和n.请你找出并返回strs的最大子集的大小,该子集中最多有m个0和n个1.

解题思路:
方法1:
利用动态规划法,状态方程为:
dp[i][j]=max(dp[i][j],1+dp[i-zero][j-zero]
给定一个字符串数组和m,n,其中所有的字符都是由0和1组成的.问能否从数组中取出最多的字符串,使得这些取出的字符串中所有的0的个数
<=m,1的个数<=n.
这道题是典型的01背包问题.只不过是二维的背包问题.在n个物品中选出一定的物体,尽量完全填满m维和n维的背包.为什么尽量填满?因为
不一定完填满背包.

`dp[i][j]代表尽量填满容量为(i,j)的背包装下的物品总数,状态转移方程为:dp[i][j]=max(dp[i][j],1+dp[i-zero][j-zero].
其中zero代表的是当前装入物体在m维上的体积,也即0的个数.one代表的是当前装入n维上的体积,也即1的个数.每添加一个物体,比较
当前(i,j)的背包装下的物品总数(i-zero,j-zero)的背包装下的物品总数+1,比较这两者的大小,保存两者的最大值.每添加一个物品就
刷新这个二维背包,直到所有物品都扫完一遍.dp[m][n]中存储的就是最终的答案.时间复杂度为O(n*M*N).`