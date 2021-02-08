/*
Given a positive integer K,you need to find the length of the smallest positive integer N 
such that N is divisible by K,and N only contains the digit 1.
Return the lenght of N.If there is no such N,return -1.
Note:N may not fit in a 64-bit signed integer.

Example 1:
Input:K=1
Output:1
Explantion:The smallest is N=1,which 1. answer has length.

Example 2:
Input:K=2
Output:-1
Explantion:There is no such by 2.positive integer N divisible.

Example 3:
Input:K=3
Output:3
Explantion:The smallest is N=111,which 3. answer has length.

Constraints:
1<=K<=10^5

题目大意:
给定一个正整数K,求能否找到一个全为1的正整数可以整除K,求这个最小的长度为多少?注意这个整数N可以大于64位有符号
的Interge正整数.

解题思路:
这个一道典型的数学问题,按照题目的要求从小到大进行遍历.记得小学老师讲过,能被2整除的正整数必定是偶数,末尾为0或者
为5的正整数必然可以整除5.这样就可以初始条件判断K数是否能整除2和5,若满足,直接返回-1.此外,需要注意的是,整除K的
数可能发生越界的情况,根据抽屉原理,应该是高中的知识,每次循环过程中对K进行求余数.这样就可以避免越界.而且遍历的
最大值应该设为K,若超过K则会重复循环之前的结果.
*/

#include <iostream>

using namespace std;

class Solution{
public:
    int smallestRepunitDivByK(int K){
        if(K&1==0||K%5==0) return -1;
        int N=0;
        for(int i=1;i<=K;++i){
            N=(10*N+1)%K;//公示:G(n)=F(n)%K->F(n)=(F(n-1)*10+1)%K,G(n)=G(N-1)*10+1
            if(N==0) return i;
        }
        return -1;
    }
};
int main(int argc,char* argv[]){
    cout<<Solution().smallestRepunitDivByK(9)<<endl;
    return 0;
}