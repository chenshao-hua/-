For an integer n,we call k>=2 a good base of n ,if all digits of n base k are 1.
Now given a string representing n,you should return the smallest good base of n in string 
format.

Example 1:
Input:"13"
Output:"3"
Explanation:13 base 3 is 111.

Example 2:
Input:"4681"
Output:"8"
Explanation:4681 base 8 is 11111.

Example 3:
Input:"1000000000000000000"
Output:"999999999999999999"
Explanation:1000000000000000000 base 999999999999999999 is 11.

题目大意:
对于给定的整数n,如果n的k(k>=2)进制数的所有数位全为1,则称k(k>=2)是n的一个好进制.以字符串的形式给出n,然后以字符串
的形式返回n的最小的好进制.

解题思路:
考虑到数字是正整数,而且可能很大,利用uint64位存储.
这道题需要k的前m项和为n,则k^m+k^(m-1)+....+k+1,则1-k^m/(1-k)=n,题目已知k>=2,m>=1,
m=logk(kn-n+1)-1<logk(kn)=l+logk(n); 所以1<=m<=log2(n),
可以得到 nk-n+1<nk, 则k<n(1/m). 则2<=k<n(1/m),再利用二分查找逼近最小的k.
