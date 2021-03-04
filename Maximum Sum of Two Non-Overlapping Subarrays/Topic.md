Given an array A of non-negative integers,return the maximum sum of elements in two 
non-overlapping(contiguous)subarrays,which have lengths L and M.(For clarification,the L-
length subarrays could occur before or after the M-length subarrays.)
Formally,return the largest V for which V=(A[i]+A[i+1]+...+A[i+L-1]+(A[j]+A[j+1]+...+A[j+M-1]
) and either.
(1) 0 <= i < i+L-1 < j+M-1 < A.length,or 0 <= j < j+M-1 < i < i+L-1 < A.length.

Example 1:
Input: A=[0,6,5,2,2,5,1,9,4],L=1,M=2
Output: 20
Explanation: One choice of subarrays is [9] with length 1, and [6,5] with length 2.

Example 2:
Input: A=[3,8,1,3,2,1,8,9,0],L=3,M=2
Output: 29
Explanation: One choice of subarrays is [3,8,1] with length 3, and [8,9] with length 2.

Example 3:
Input: A=[2,1,5,6,0,9,5,0,3,8],L=4,M=3
Output: 31
Explanation: One choice of subarrays is [5,6,0,9] with length 4, and [3,8] with length 3.

题目大意:
给定一个非负数组A,以及长度为L和M,找出不重叠且长度分别为L和M的两个连续子数组,对顺序没有要求,求这两个子数组最大之
和为多少.

解题思路:
方法1:
利用sliding window维持两个L和W,直接枚举.超出时间限制

方法2:
首先建立数组的前n项累加和,然后定义Lmax为在最后M个元素之前的长度为L的子数组元素的最大之和,同样道理Mmax表示为在最
后L个元素之前的长度为M的子数组元素的最大之和.结果ans初始化为L+M的个元素之和,然后枚举整个数组,从L+M开始进行遍历
,先更新Lmax和Mmax,其中:Lmax表示更新A[i-M]-A[i-M-L],Mmax表示更新A[i-L]-A[i-M-L].然后再取
Lmax+A[i]-A[i-M]和Mmax+A[i]-A[i-L]之间的最大值用来更新ans.