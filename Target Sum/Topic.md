You are given a list of non-negative integers,a1,a2,...,an,and a target,S.Now you have 
2 symbols + and -.For each integer,you should choose one from + and - as its new symbol.
Find out how many ways to assign symbols to make sum of integers equal to target S.

Example 1:
Input:nums=[1,1,1,1,1],S=3
Output:5
Explanation:
-1+1+1+1+1=3
+1-1+1+1+1=3
+1+1-1+1+1=3
+1+1+1-1+1=3
+1+1+1+1-1=3
There are 5 ways to assign symbols to make the sum of nums be target 3.

Note:
1.The length of the given array is positive and will not exceed 20.
2.The sum of elements in the given array will not exceed 1000.
3.Your output answer is guaranteed to be fitted in a 32-bit integer.

题目大意:
给定一个非负整数数组nums和一个目标数S.给出符号"+"和"-",对于数组中的任意一个整数,可以从这两种符号中任选其中
一个放在其前面.返回可以使得数组的和等于目标数S的所有添加符号的方法数.

解题思路:
方法1:
利用dfs深度搜索算法,每次遍历每个元素的正负值,递归退出条件,大于数组长度或者等于数组长度时此时目标值不为零,进行
增加1操作是目标值为零且等于数组长度.需要注意的是遍历数组某个元素时,需要判断当前k值是否小于数组长度,以免越界.

方法2:
dfs+剪枝优化

方法3:
动态规划
题目要求数组的元素加上+和-,其实相当于把数组分成了2组,一组全部都加+号,另外一组全部加-号.则存在如下关系:
sum(P)-sum(N)=target,两边同时加上sum(P)+sum(N),则
sum(P)+sum(N)+sum(P)-sum(N)=target+sum(P)+sum(N)
因此2*sum(P)=target+sum(nums),那么这道题就转换成了,能否在数组中找到这样一个集合,和等于
(target+sum(nums))/2.其中dp[i]存储的是能使和为i的方法个数.
若和不是偶数,即不能被2整除,直接输出0.