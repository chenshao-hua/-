/*
Given an array of integers arr,sort the array by performing a seriers of pancake flips. 
In one pancake flip we do the following steps:
(1)choose an integer k where 1<=k<=arr.length.
(2)Reverse the sub-array arr[1...k].
For example,if arr=[3,2,1,4] and we performed a pancake flip choosing k=3,we reverse the
sub-array[3,2,1],so arr=[1,2,3,4] after the pancake flip at k=3.
Return the k-values correspoding to a sequence of pancake flips that sort arr.Any valid answer
that sorts the array within 10*arr.length flips will be judged as correct.

Example 1:
Input:arr=[3,2,4,1]
Output:[4,2,4,3]
Explanation:
We perform 4 pancake flips,with k values 4,2,4,and 3.
Starting state:arr=[3,2,4,1]
After 1st flip (k=4):arr=[1,4,2,3]
After 2nd flip (k=2):arr=[4,1,2,3]
After 3rd flip (k=4):arr=[3,2,1,4]
After 4st flip (k=3):arr=[1,2,3,4],which is sorted.
Notice that we return an array of the chosen k values of the pancake flips.

Example 2:
Input:arr=[1,2,3]
Output:[]
Explanation:
The input is already sorted,so that is no need to flip anything.
Note that  other answers,such as [3,3],would also be accepted.

题目大意:
给定一个长度为n的数组.任意翻转前k个数字,范围为(1~n),求如何翻转可以使得数组有序.题目不限定具体的翻转方法,只需要
在10*n次数内就可以.

解题思路:
方法1:
这道题一个容易理解的方法是每次先找出最大的元素,然后翻转到首位置,接着翻转整个数组,就最大的元素到达最后面的位置.
接着重复之前的步骤,找出次大的元素,翻转到最大元素的前面.重复这些步骤,直到最后元素为1.可以使用reverse函数进行
数组翻转,注意这是左闭右开区间,

方法2:
算法优化,上面的思路时间复杂度达到O(n^2),进行优化.
每次把当前区间比如[0,i]的最大元素移动到最后面.此时该区间最大的数的下标为j,那么可以通过翻转两次达到目的:
[1,j+1],将该数移动到区间头部;
[2,i+1],将该数移动到区间尾部;
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    vector<int> pancakeSort(vector<int>& arr){
        vector<int> ans;
        int n=arr.size();
        while(n>1){
            int tmp=INT_MIN,k=0;
            for(int i=0;i<n;i++){
                if(arr[i]>tmp){
                    tmp=arr[i];
                    k=i;
                }
            }
            reverse(arr.begin(),arr.begin()+k+1);
            ans.push_back(k+1);
            reverse(arr.begin(),arr.begin()+n);
            ans.push_back(n);
            n--;
        }
        return ans;
    }

    vector<int> pancakeSortTwo(vector<int>& arr){
        vector<int> res;
        int n=arr.size();
        for(int i=n-1;i>0;--i){
            int j=max_element(arr.begin(),arr.begin()+i+1)-arr.begin();
            if(j>0){
                reverse(arr.begin(),arr.begin()+j+1);
                res.push_back(j+1);
            }
            reverse(arr.begin(),arr.begin()+i+1);
            res.push_back(i+1);
        }
        return res;
    }
};

int main(int argc,char* argv[]){
    vector<int> arr={3,2,4,1};
    vector<int> ans=Solution().pancakeSortTwo(arr);
    for(const auto& a:ans){
        cout<<a<<" ";
    }
    cout<<endl;
    return 0;
}