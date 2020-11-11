/*
题目描述：
给定一个增序的整数数组和一个值，查找该值第一次和最后一次出现的位置

示例：
输入的是一个数组和一个值，输出为该值第一次出现的位置和最后一次出现的位置（从0开始）;
如果不存在该值，则返回值都设为-1.

Input:nums=[5,7,7,8,8,10],target=8
Output:[3,4]

解题思路：
解法一：利用二分查找的思想，调用lower_bound和upper_bound两个函数，使用左闭右开的写法
解法二：利用multimap容器，equal_range函数
*/
#include <iostream>
#include <vector>
#include <map>


using namespace std;

class Solution{
public:
     Solution(vector<int>& _nums,const int& _target):nums(_nums),target(_target){}
     vector<int> searchRange(){
         multimap<int,int> num;
         for(int i=1;i<=nums.size();i++)
             num.insert(make_pair(nums[i-1],i));

         pair<multimap<int,int>::iterator,multimap<int,int>::iterator> it=num.equal_range(target);
         /*若键不存在，则返回同一个迭代器，指向依据元素的排列顺序该键应该插入的位置*/
         if(it.first==it.second){
             return vector<int>{-1,-1};
         }else{
             return vector<int>{it.first->second,(--it.second)->second};
         }
    }
private:
     vector<int> nums;
     int target;
};

int main(int argc,char* argv[]){
    vector<int> nums={5,7,7,8,8,10};
    Solution solu(nums,8);
    vector<int> result=solu.searchRange();
    for(auto& num:result)
        cout<<num<<"  ";
    cout<<endl;
    return 0;
}