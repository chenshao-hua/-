题目

Given an array of citations(each citation is a non-negative integer) of a research,write a 
function to compute the research's h-index.

According to the definition of h-index on Wikipedia:"A scientist has index h if h of his/her N
papers have at least citations each,and the other N-h papers have no more than h citations each."

Example 1:

Input:citations=[3,0,6,1,5]

Output:3

Explanation:[3,0,6,1,5] means the researcher has 5 papers in total and each of them had received 
3,0,6,1,5 citations respectively.Since the researcher has 3 papers with at least 3 citations each
and the remaining two with no more than 3 citations each,her h-index is 3.

Note:

If there are several possible values for h,the maximum one is taken as the h-index.

题目大意:

``给定一位研究者论文被引用次数的数组,为非负整数.编写一个方法,计算研究者的h指数.h指数的定义:h代表"高引用次数",一名科研
人员的h指数是指他(她)的(N篇论文中)总共h篇论文分别被引用了至少h次.且其余的N-h篇论文的每篇被引用次数不超过h次.

例如:某人的h指数为20,这表明他已发论文中,每篇被引用了至少20次的论文总共有20篇.

解题思路:

方法1:

先将数组citations从大到小进行排序.从头进行枚举i,找到一个值i满足citations[i]>=i+1,citations[i+1]<=i+1,此时
i+1就是所求的.

方法2:

返回的值是论文的篇数,则h值一定在数组的长度n范围内.可以利用一个数组存储大于或等于n时的个数,小于则直接进行计数.
然后从末尾进行遍历即可.

