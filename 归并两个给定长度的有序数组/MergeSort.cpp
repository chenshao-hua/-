/*
题目描述：
给定两个有序指定长度的数组，把两个数组合并为一个。

示例：
输入是两个数组和它们分别的长度m和n。其中第一个数组的长度被延长至m+n，多出的n位被
0填充。题目要求把第二个数组归并到第一个数组上，不需要开辟额外的空间。

Input:nums1=[1,2,3,0,0,0],m=3,num2=[2,5,6],n=3
Output:nums1=[1,2,2,3,5,6]

解题思路：
因为这两个数组都排序好，可以设置两个指针，分别放在两个数组元素的末尾，即nums1的m-1位
和nums2的n-1位。每次将较大的那两个元素复制到num1的后边，然后向前移动一位。因为我们需要
定位nums1的末尾，所以需要设置第三个指针，以便复制。
具体是：设定三个指针，其中m和n当做两个数组的末尾指针，另外一个pos指针起始位置为m+n-1。每次
向前移动m或者n的时候，也要向前移动pos。需要注意的是，当num1数组的所有元素已经复制完了，记得
继续复制num2；当nums2数组的所有元素复制完了，剩余的nums1的元素不需要排序，因为它们已经
排序好。
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    void mergesort(vector<int>& nums1,vector<int>& nums2,int m,int n){
        int pos=m-- +n-- -1;
        while(m>=0&&n>=0){
            nums1[pos--]=nums1[m]>nums2[n]?nums1[m--]:nums2[n--];
        }
        while(n>=0){
            nums1[pos--]=nums2[n--];
        }
    }
};
int main(int argc,char* argv[]){
    vector<int> nums1={1,2,3,0,0,0,0};
    vector<int> nums2={2,5,6,8};
    Solution solu;
    solu.mergesort(nums1,nums2,3,4);
    for(auto& it:nums1)
         cout<<it<<"  ";
    cout<<endl;
    return 0;
}