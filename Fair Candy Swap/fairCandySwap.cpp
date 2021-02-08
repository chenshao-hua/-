/*
Alice and Bob have candy bars of different sizes:A[i] is the size of the i -th bar of candy 
that Alice has,and B[i] is the size of j -th bar of candy that Bob has.
Since they are friends,they would like to exchange one candy bar each so that after the 
exchange,they both have the same total amount of candy.(The total amount of candy a person has 
is the sum of the sizes of candy bars they have.)
Return an integer array ans where ans[0] is the size of the candy bar that Alice must 
exchange,and ans[1] is the size of the candy bar that Bob must exchange.
If there are multiple answers,you may return any one of them.It is guaranteed an answer 
exists.

Example 1:
Input: A=[1,1],B=[2,2]
Output: [1,2]

Example 2:
Input: A=[1,2],B=[2,3]
Output: [1,2]

Example 3:
Input: A=[2],B=[1,3]
Output: [2,3]

Example 4:
Input: A=[1,2,5],B=[2,4]
Output: [5,4]

题目大意:
爱丽丝和鲍勃有不同大小的糖果棒:A[i]是爱丽丝拥有的第i块糖的大小,B[j]是鲍勃拥有的第j块糖的大小.因为他们是朋友,所
以他们想交换一个糖果棒,这样交换后,他们都有相同的糖果总量(一个人拥有的糖果总量是他们拥有的糖果棒大小的总和)
返回一个整数数组ans,其中ans[0]是爱丽丝必须交换的糖果棒的大小,ans[1]是Bob必须交换的糖果棒的大小.
如果有多个答案,你可以返回其中任何一个.保证答案存在.

解题思路:
方法1:
先遍历两个数组求出各自的和以及总和n,这样就得到要保证A和B相等,需要满足n/2.在逐个枚举其中一个数组,比如A的各个元素,
达到和为n/2时,B数组中是否存在此元素,条件为:n/2-(sum(A)-A[i]).其实就是寻找:x=y+(sum(A)-sum(B))/2.
哈希或者二分查找
方法2:
利用双指针进行遍历.
*/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <numeric> //accumulate

using namespace std;

class Solution{
public:
    vector<int> fairCandySwapOne(vector<int>& A, vector<int>& B){
        int ans1,ans2,sumA=0,sumB=0;
        //multiset<int> res;//利用set数组查找快,底层是红黑树.
        for(auto& a:A){
            sumA+=a;
        }
        for(auto& b:B){
            sumB+=b;
            //res.insert(b);
        }
        int sum=(sumA+sumB)>>1;
        for(auto& a:A){
            // if(res.count(sum-(sumA-a))){
            //     ans1=a,ans2=sum-(sumA-a);
            //     break;
            // }
            ans2=sum-(sumA-a);
            if(find(B.begin(),B.end(),ans2)!=B.end()){
                ans1=a;
                break;
            }
        }
        return {ans1,ans2};
    }
    //算法优化,直接使用二分查找,不用set容器
    vector<int> fairCandySwapTwo(vector<int>& A, vector<int>& B){
        int sumA=0,sumB=0,l,r;
        for(auto& a:A){
            sumA+=a;
        }
        for(auto& b:B){
            sumB+=b;
        } 
        int diff=(sumB-sumA)/2;
        sort(B.begin(),B.end(),less<int>());//从小到大排序,默认,可以省略
        for(auto& a:A){
            l=0,r=B.size()-1;
            int b=a+diff;
            while(l<=r&&l>=0&&r<B.size()){
                int mid=(l+r)>>1;
                if(B[mid]==b) 
                    return {a,b};
                else if(B[mid]>b) 
                    r=mid-1;
                else
                    l=mid+1;         
            }
        }
        return {-1,-1};
    }
     //算法优化,直接使用双指针
     vector<int> fairCandySwap(vector<int>& A, vector<int>& B){
         int sumA=accumulate(A.begin(),A.end(),0);
         int sumB=accumulate(B.begin(),B.end(),0);
         int target=(sumA-sumB)>>1;

         //排序
         sort(A.begin(),A.end(),less<int>());
         sort(B.begin(),B.end(),less<int>());

         int i=0,j=0,nA=A.size(),nB=B.size();//i,j双指针分别指向A,B的开始位置
         while(i<nA&&j<nB){
             int cur=A[i]-B[j];
             if(cur==target){
                 return {A[i],B[j]};
             }else if(cur>target){
                 ++j;
             }else{
                 ++i;
             }
         }
         return {};//不存在
     }
};

int main(int argc,char* argv[]){
    vector<int> A={1,2,5,6},B={2,4,6};
    vector<int> ans=Solution().fairCandySwapTwo(A,B);
    for(auto& a:ans){
        cout<<a<<" ";
    }
    cout<<endl;
    return 0;
}