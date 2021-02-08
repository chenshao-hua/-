/*
There is a list of sorted integers from 1 to n.Starting from left to right,reomove the first 
number and every other number aferward until you reach the end of the list.
Repeat the previous step again,but this time from right to left,remove the right most number
 and every other number from the remaining numbers.
We keep repeating the steps again,alternating left to right and right to left,until a single 
number remains.
Find the last number that remains starting with a list of length n.

Example 1:
Input:n=9
Output:6
Explanation:
1 2 3 4 5 6 7 8 9
2 4 6 8
2 6
6
题目大意:给定一个从1到n排序的整数列表.首先,从左到右,从第一个数字开始,每隔一个数字进行删除,直到列表的末尾.
第二步,在剩下的数字中,从右到左,从倒数第一个数字开始,每隔一个数字进行删除,直到列表开头.
我们不断重复这两步,从左到右和从右到左交替进行,直到只剩下一个数字.返回长度为n的列表中,最后剩下的数字.

解题思路:
方法1:
利用链表进行存储1~n个整数,方便进行正序(指针处于begin)、反序删除(指针处于end),若size为1时跳出循环.超时

方法2:
数字归纳法.若n=1时,f(x)=1;若n>1时,f(x)=2*(n/2+1-f(n/2));

*/

#include <iostream>
#include <list>

using namespace std;

class Solution{public:
    int lastRemaining1(int n){
        list<int> ans;
        for(int i=1;i<=n;i++){
            ans.push_back(i);
        }
        while(ans.size()!=1){
            // if(ans.size()==1){
            //     break;
            // }
            auto i=ans.begin();
            while(true){
                ans.erase(i++);
                if(ans.size()==1) return ans.back();
                if(i==ans.end()) break;
                i++;
                if(i==ans.end()) break;
            }
        
            auto j=ans.rbegin();
            while(true){
                ans.erase(--(j.base()));//反向迭代器删除元素 
                if(ans.size()==1) return ans.back();
                if(j==ans.rend()) break;
                j++;
                if(j==ans.rend()) break;
            }
        }
        return ans.back();

    }
    int lastRemaining2(int n){
        if(n==1) return n;
        return 2*(n/2+1-lastRemaining2(n/2));
    }
};
int main(int argc,char* argv[]){
    Solution so;
    for(int i=1;i<=300;i++){
        cout<<so.lastRemaining1(i)<<" "<<so.lastRemaining2(i)<<endl;
    }
    return 0;
}