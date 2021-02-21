A query word matches a given pattern if we can insert lowercase letters to the pattern word
so that it equals the query.(We may insert each character at any position,and may insert 0 
characters.)
Given a list of queries,and a pattern,return an answer list of booleans,where answer[i] is 
true if and only if queries[i] matches the pattern.

Example 1:
Input: queries=["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"],
       pattern="FB"
Output:[true,false,true,true,false]
Explanation: 
"FooBar" can be generated like this "F" + "oo" + "B" + "ar".
"FootBall" can be generated like this "F" + "oot" + "B" + "all".
"FrameBuffer" can be generated like this "F" + "rame" + "B" + "uffer".

Example 2:
Input: queries=["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"],   
        pattern="FoBa"
Output: [true,false,true,false,false]
Explanation: 
"FooBar" can be generated like this "Fo" + "o" + "Ba" + "r".
"FootBall" can be generated like this "Fo" + "ot" + "Ba" + "ll".

Example 3:
Input: queries=["CompetitiveProgramming","CounterPick","ControlPanel"],pattern="CooP"
Output: [false,false,true]

题目大意:
如果我们可以将小写字母插入模式串pattern得到待查询项query,那么待查询项与给定模式串匹配.我们可以在任何位置插入每个字符,也可以插入0个字符.
给定待查询列表queries,和模式串pattern,返回由布尔值组成的答案列表answer.只有在待查项queries[i]与模式串pattern匹配时,answer[i]才为true,否则为false.


方法1:
直接枚举,只需要枚举每个单词queries[i]中的当个字符是否与pattern相等即可,判断条件是当每个单词遍历完成后判断
pattern是否已经完成,并且利用flag标记符记录单词中是否已经出现过pattern不存在的大写字符.

方法2:
双指针.在枚举每个单词queries[i]时,设置左右两个指针,而且pattern也设置左右两个指针.需要设计一个变量n统计是否等
于pattern的长度,当queries还没退出是否,考虑到小写字符可能重复,在n+1时需要进行条件判断.

