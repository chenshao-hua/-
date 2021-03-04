We write the integers of A and B (in the order they are given) on two separate horizontal
 lines.Now,we may draw connecting lines:a straight line connecting two numbers A[i] and B[i]
 such that:
 (1)A[i]==B[i];
 (2)The line we draw does not intersect any other connecting (non-horizontal) line.
 Note that a connecting lines cannot intersect even at the endpoints:each number can only
  belong to one connecting line.
  Return the maximum number of connecting lines we can draw in this way.

Example 1:
Input:A=[1,4,2],B=[1,2,4]
Output:2
Explanation:We can draw 2 uncrossed lines as in the diagram.We cannot draw 3 uncrossed
lines.Because the line from A[1]=4 to B[2]=4 will intersect the line from A[2]=2 to 
B[1]=2.

Example 2:
Input:A=[2,5,1,2,5],B=[10,5,2,1,5,2]
Output:3

Example 3:
Input:A=[1,3,7,1,7,5],B=[1,9,2,5,1]
Output:2

题目大意:
给出A和B两个数组,并且上下并列排放,存在两个数组大小不一致,然后用线进行连接相同的数字,求最多能连接多少根线,而且
不会发生相交.

解题思路:
从例子可以看出在数组A中4和2都连上则会发生相交,这是因为A和B数组中4和2对应的顺序不一致.再看例子2,然后连上5,1,2或
者2,1,2或者5,2,5都是可以的.从这些例子可以知道这样的一个结论,本题的本质是在求最长公共子序列.通过dp动态规划可以
容易解决此问题.假设一个二维数组dp,其中dp[i][j]表示数组A的前i个数字和数组B的前j个数字的最长相同的子序列搞得数字
个数,大小初始化为行A的长度m为(m+1),列B的长度n为(n+1).那如何更新dp[i][j]呢?若A[i]和A[j]对应的位置字符相同
时,表示当前的最长相同的子序列+1,则dp[i][j]=dp[i-1][j-1]+1.若不相等时,考虑到错位比较,可以A和B的前一个元素
进行最大化,即dp[i][j]=max(dp[i-1][j],dp[i][j-1]).最后的结果为dp[m][n].
