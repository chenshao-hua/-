/*
题目描述:
给定一个数字n,求小于n的质数的个数.

Example 1:
Input:10
Output:4
其中[2,3,5,7]
解题思路:
这道题比较简单可以利用遍历法,判断是否为质数即可.
此外,可以根据艾拉托斯特尼筛法是非常常用的,判断一个整数是否是质数的方法.并且可以在判断一个整数n的时候,同时
判断所小于n的整数,因此非常适合这道题.其原理通俗易懂:从1到n遍历,假设当前遍历到m,则把所有小于n的,且是m的倍数
的整数标为和数.遍历完成后,没有被标为和的数字即为质数.
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution{
public:
    int countPrimes(int n){       
        if(n<=2){
            return 0;
        }

        int count=1,board=0;
        bool flag;
        for(auto i=3;i<n;i+=2){
            board=sqrt(i),flag=true;
            for(auto j=2;j<=board;j++){
                if(i%j==0){
                    flag=false;
                    break;
                }
            }
            if(flag){
                count++;
            }
        }
        return count;
    }

    int countprimes(int n){
        if(n<=2){
            return 0;
        }
        vector<bool> prime(n,true);
        int count=n-2;/*去掉不是质数的1和末尾的n*/
        for(auto i=2;i<n;i++){
            if(prime[i]){
                for(auto j=2*i;j<n;j+=i){
                    if(prime[j]){
                        prime[j]=false;
                        count--;
                    }
                }
            }
        }
        return count;
    }

    int countprime(int n){
        if(n<=2) return 0;
        vector<bool> prime(n,true);
        int i=3,board=sqrt(n),count=n/2;/*剔除偶数*/
        while(i<=board){
            /*最小质因子一定小于等于开方数*/
            for(int j=i*i;j<n;j+=2*i){          
                if(prime[j]){/*避免偶数和重复遍历*/
                    count--;
                    prime[j]=false;
                }
            }
            do{
                i+=2;
            }while(i<=board&&!prime[i]);/*避免偶数和重复遍历*/
        }
        return count;
    }
};

int main(int argc,char* argv[]){
    cout<<Solution().countprime(12)<<endl;
    return 0;
}