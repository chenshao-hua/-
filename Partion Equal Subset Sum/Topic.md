Given a non-empty array containing only positive integers,find if the array can be 
partitioned to two subsets such that the sum of elements in both subsets is equal.

Note:
1.Each of the array element will not exceed 100.
2.The array size will not exceed 200.

Example 1:
Input:[1,5,11,5]
Output:true
Explanation:
The array can be partitioned as [1,5,5] and [11].

Example 2:
Input:[1,2,3,5]
Output:false
Explanation:
The array cannot be partitioned into equal sum subsets.

题目大意:
给定一个只包含正整数的非空数组,是否可以将这个数组分割成两个子集,使得两个子集的元素之和相等.

解题思路:
方法1:
dfs+剪枝优化
要满足sum(P)=sum(Q),根据sum(P)+sum(Q)=sum(nums),可得sum(P)=sum(nums)/2.此问题转换为
在数组中找出是否存在子集满足target=sum(nums)/2.
只要找到一个temp值等于target即可返回,剪枝的条件是在枚举数组中temp!=target,此外路径之和不能大于target.
可惜超时。

方法2:
动态规划

