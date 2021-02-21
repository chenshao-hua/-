Given an array A of integers,return the length of the longest arithmetic subsequence in A.
Recall that a subsequence of A is a list A[i_1], A[i_2]....,A[i_k] with 0<=i_1<i_2...<i_k
=A.length-1,and that a sequence B is arithmetic if B[i+1]-B[i] are all the same value(for 0<=i<B.length-1).

Example 1:
Input:A=[3,6,9,12]
Output:4
Explanation:
The whole array is an arithmetic sequence with steps of lenght=3.

Example 2:
Input:A=[9,4,7,2,10]
Output:3
Explanation:
The longest arithmetic subsequence is [4,7,10].

Example 3:
Input:A=[20,1,15,3,10,5,8]
Output:4
Explanation:
The longest arithmetic subsequence is [20,15,10,5].

Constraints:
(1)2<=A.length<=1000;
(2)0<=A[i]<=500;

题目大意:
给定一个整数数组,求最长的等差子序列的长度,此序列满足下标增大趋势,不能排序.

解题思路:
此题三层遍历,前两层选定两个数作为等差数列的值,第三层遍历选定两个元素后面的值是否满足等差数列,时间复杂度太大.
这道题利用dp动态规划很容易解决问题.

方法1:
动态规划算法.设置一个二维数组dp[i][j],表示在区间[0,i]中的差值为j的最长等差数量的长度-1,减1的操作是起始位置的数字并没有被计算进去.由于题目限定数字的范围,0~500之间,因此差值的范围在-500~500之间,考虑到索引不能为负数,因此
可以给差值加上1000,这样等差数列的差值就在500到1500之间了,dp的初始化大小为nX2000.更新dp值的时候,先枚举一遍数组,对于每个枚举到的元素,再枚举一遍前面的元素,计算出差值diff,再+1000,然后此时满足dp[i][diff]=dp[j][diff]+1,并且更新最大长度ans=max(ans,dp[i][diff]).最后结果+1.

方法2:
动态规划优化+map
dp[i][j]表示A[i]和A[j]为等差数列的等差值,则diff=2*A[i]-A[j]为等差数列的A[i]的前一个值,map记录每个在i之前出现的最后一个下标,key是A的数值,val是这个数值的index;
