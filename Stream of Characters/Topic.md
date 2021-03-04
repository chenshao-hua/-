Implement the StreamChecker class as follows:
(1)StreamChecker(words):Constructor,init the data structure with the given words.
(2)query(letter):returns true if and only for some k>=1,the last k characters queried(in 
order from oldest to newest,including this letter just queried)spell one of the words in
the given list.

Example:
StreamChecker streamChecker = new StreamChecker(["cd","f","kl"]); // init the dictionary.
streamChecker.query('a');          // return false
streamChecker.query('b');          // return false
streamChecker.query('c');          // return false
streamChecker.query('d');          // return true, because 'cd' is in the wordlist
streamChecker.query('e');          // return false
streamChecker.query('f');          // return true, because 'f' is in the wordlist
streamChecker.query('g');          // return false
streamChecker.query('h');          // return false
streamChecker.query('i');          // return false
streamChecker.query('j');          // return false
streamChecker.query('k');          // return false
streamChecker.query('l');          // return true, because 'kl' is in the wordlist

Note:
(1) 1 <= words.length <= 2000;
(2) 1 <= words[i].length <= 2000;
(3) Words will only consist of lowercase English letters;
(4) Queries will only consist of lowercase English letters;
(5) The number of queries is at most 40000;

题目大意:
给定一个字符串数组,然后每次用小写字母进行查询,判断查询过的小写字母按照先后顺序进行拼接能否在字符串数组中找到.
注意,若存在某些 k >= 1,可以用查询的最后 k个字符 (按从旧到新顺序,包括刚刚查询的字母) 拼写出给定字词表中的某一字
词时,返回true.否则,返回false.

解题思路:
方法1:
假设一个字符串str,用于存储每次query的字母,相当于对字符串str进行追加操作,然后枚举直接str是否存在连续的子字符串
正好能在words数组中.超出时间限制.

方法2:
前缀树Trie(字典树),定义一个结构体,里面有两个变量,布尔型isWord,用于标记前缀是否是一个完整单词,另一个是next
数组,里面有26个Trie节点,指向下一个字符.然后声明前缀树的根节点为root,并且定义字符串queryStr,用于存储每次
查询的字符.这样在构建函数时,其实就是在构建这个前缀树,遍历每个单词,从最后的字符开始处理,若当前节点的next数组中
对应位置不包含该字符,则新建Trie节点,然后当前节点移动到新建的节点并且继续进行循环,完成之后标记isWord为true的
操作.实现query函数时进行相似的操作,先把字符加入queryStr,然后从其末尾往前进行遍历,取出next数组中对应位置的
节点,若存在而且isWord为true,则说明存在这样的单词,直接返回true,否则继续遍历.
