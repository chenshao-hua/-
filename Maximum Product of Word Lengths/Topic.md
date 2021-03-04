Given a string array words,find the maximum value of length(word[i])*length(word[j]),where 
the two words do not share common letters.You may assume that each word will contain only 
lower case letters.If no such two words exist,return 0.

Example 1:
Input:["abcw","baz","foo","bar","xtfn","abcdef"]
Output:16
Explanation:The two words can be "abcw","xtfn"

Example 2:
Input:["a","ab",""abc","d","cd","bcd","abcd"]
Output:4
Explanation:The two words can be "ab","cd".

Example 3:
Input:["a","aa","aaa","aaaa"]
Output:0
Explanation:No such pair of words.

题目大意:
给定一个字符串数组words,找到一对单词组的乘积的最大值.要求这两个单词不含有公共的字母.可以认为每个单词只包含小写
字母.若不存在则返回0.

解题思路:
这道题利用位运算&容易求出结果.若存在X&Y=0,则X与Y不相等.那么可以将字符串都编码成二进制数,再进行&运算可以判断
出字符串中是否存在相同的字母,分别枚举各个单词维护最大乘积.这样简单介绍下,如何将字符串编码成二进制的？可以考虑到
每个字字母相对于字母'a'的距离,根据这个距离然后将1进行移动几位.a-z对应0-25位,最大可以理解为25位,若相应的位置为1,
则表明该位置存在响应的字母.那么一个单词最终二进制,需要再每次枚举一个单词时,再用|或运算进行统计,例如:
a   1    < 1(移动0位)
b   10   < 2(移动1位)
c   100  < 4(移动2位)
ab  11   < 3(移动0位,移动1位,或运算)
ac  101  < 5(移动0位,移动2位,或运算)
abc 111  < 7(移动0位,移动1位,移动2位,或运算)