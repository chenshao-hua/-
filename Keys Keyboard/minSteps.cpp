/*
Initially on a notepad only one character 'A' is presest.You can perform two operations 
on this notepad for each step:
（1）Copy All:You can copy all the characters present on the notepad(partial copy is not allowed).
（2）Paste:You can paste the characters which are copied last time.

Given a number n.You have to get exactly n 'A' on the notepad by performing the minimum 
number of steps permitted.Output the minimum number of steps to get n 'A'.

Example 1:

Input: 3
Output: 3
Explanation:
Intitally,we have one character 'A'.
In step 1,we use Copy All operation.
In step 2,we use Paste operation to get 'AA'.
In step 3,we use Paste operation to get 'AAA'.

题目大意:
给定一个字母A,你可以每次选择复制全部字符或者粘贴上一次复制的字符,求最少需要多少次操作可以
把字符串延展到指定长度.

解题思路:
方法1:
素数分解.所有的操作都是以copy为首,paste结束.这样可以分成多组,[cpp][cpppp][cp]....,
假设每组的长度分别为:x1,x2,x3...xn.
（1）第一组操作后,字符串总共有x1个A;
（2）第二组操作后,字符串总共有x1*x2个A;
（3）第n组操作后,字符串总共有x1*x2....*xn个A;
若xi是合数,则存在xi=p*q,那么可以分成两组,第一组包含1个copy和p-1个paste,第二组包含1个copy
和q-1个paste.

证明这种分割方式下需要的次数达到最少.p+q<=p*q,则1<=(p-1)(q-1),当p且q>=2时条件都成立.
本题就是N的素数分解过程.

方法2:
动态规划.需要乘除法来计算位置,因为粘贴操作是倍数增加的.设定数组dp[i],其中位置i表示延展到长度i的
最少操作次数.对于每个位置j,如果j可以被i整数,那么长度i就可以由长度j操作得到,其操作次数等价于把一个
长度为1的A延展到长度为i/j.因此可以得到递推公式:
dp[i]=dp[j]+dp[i/j]
*/
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
class Solution{
public:
    int minSteps1(int n){
        int ans=0,d=2;/*2是最小的素数因子*/
        while(n>1){
            while(n%d==0){
                ans+=d;/*整除则证明当前n仍为其素数因子*/
                n/=d;
            }
            /*若不是则继续进行试探*/
            d++;
        }
        return ans;
    }
    int minSteps2(int n){
        int ans=0,d=0;
        while(n!=1){
            d=findMaxDivisor(n);
            ans+=n/d;
            n=d;
        }
        return ans;
    }

    int minSteps(int n){
        vector<int> dp(n+1);
        int h=sqrt(n);
        for(int i=2;i<=n;i++){
            dp[i]=i;
            for(int j=2;j<=h;j++){
                if(i%j==0){
                    dp[i]=dp[j]+dp[i/j];
                    break;
                }
            }
        }
        return dp[n];
    }
private:
    /*找最大因数,范围:1<=d<=d/2*/
    int findMaxDivisor(int n){
        int max=n/2;
        for(int i=max;i>=2;i--){
            if(n%i==0)
               return i;
        }
        return 1;
    }
};

int main(int argc,char* argv[]){
    cout<<Solution().minSteps(6)<<endl;
    return 0;
}