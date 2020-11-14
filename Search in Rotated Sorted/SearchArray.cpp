/*前言：
目前准备每天刷一道题leetcode的题目，以此来激励那些零基础入门的人，千万不要被什么
科班和非科班的说法吓倒了，计算机这个行业只要你肯努力，没有什么逾越不了的鸿沟。
只要你肯努力，一份努力，一份汗水，在程序员这个职业，你的每一份付出都会得到对应的那
一份汇报，尊重学习规律，循序渐进，别想着一口吃个胖子，罗马也不是一天建成的，有朝一
日，你终会变成你想成为的人。
*/

/*
题目描述：
一个原本增序的数组被首尾相连后按某个位置断开(比如[1,2,2,3,4,5]-[2,3,4,5,1,2]),
在第一个和第二位断开，我们称其为旋转数组。给定一个值，判断这个值是否存在于这个旋转
数组中。

输入是一个数组和一个值，输出是一个布尔值，表示数组中是否存在该值。
示例1：
Input:nums=[2,5,6,0,0,1,2],target=0
Output:true

示例2：
Input:nums=[2,5,6,0,0,1,2],target=3
Output:false

解题思路：
利用二分法进行分析。即使数组被旋转过，但仍然可以借助数组的递增性。对于当前的中点，
若它指向的值小于等于最右端，则右区间是增序的。若它指向的值大于或等于最左端，则左
区间是增序的。如果目标值位于这个增序的区间内，可以对该区间进行二分查找，否则继续对
另一半区间继续进行二分查找。需要注意的是，数组中可能存在重复的数字，假如中点和左端点
的数子相同时，并不能判断出左右区间的有序性，需要简单的将最左端点进行右边移动一位，
然后继续二分查找。
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    Solution(vector<int>& _nums,const int& _target):nums(_nums),target(_target){}
    bool SearchArray(){
        int start=0,end=nums.size()-1,mid;
        while(start<=end){
            mid=(start+end)/2;
            if(nums[mid]==target){
                return true;
            }
            if(nums[start]==nums[mid]){
                ++start; /*无法判断左右区间的增序性*/
            }else if(nums[mid]<=nums[end]){
                /*右区间增序*/
                if(target>nums[mid]&&target<=nums[end]){
                    start=mid+1;
                }else{
                    end=mid-1;
                }
            }else{
                /*左区间增序*/
                if(target>=nums[start]&&target<nums[mid]){
                    end=mid-1;
                }else{
                    start=mid+1;
                }
            }
        }
        return false;
    }
private:
    vector<int> nums;
    int target;
};

int main(int argc,char* argv[]){
    vector<int> nums={2,5,6,0,0,1,2};
    Solution solu(nums,3);
    cout<<solu.SearchArray()<<endl;
    return 0;
}