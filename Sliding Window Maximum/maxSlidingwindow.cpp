/*
Given an array nums,there is a sliding window of size k which is moving from the very left
of the array to the very right.You can only see the k number in the window.Each time the 
sliding window moves right by one position.Return the max window.

Example 1:
Input:nums=[1,3,-1,-3,5,3,6,7],and k=3
Output:[3,3,5,5,6,7]

Explanation:
  window position       max
  ---------------       ---
[1 3 -1] -3 5 3 6 7      3
 1 [3 -1 -3] 5 3 6 7     3
 1 3 [-1 -3 5] 3 6 7     5
 1 3 -1 [-3 5 3] 6 7     5
 1 3 -1] -3 [5 3 6] 7    6
 1 3 -1 -3 5 [3 6 7]     7

 Note:
 You may assume k is always valid,1<=k<=input arrays size for non-empty array.
 Follow up:
 Could you solve it in linear time?

 题目大意:
 给定一个数组nums,有一个大小为k的滑动窗口从数组的最左侧移动到数组的最右侧,你只可以看到在滑动窗口k内的数字,
 滑动窗口每次只向右移动一位.求返回滑动窗口最大值.

 解题思路:
方法一:
直接枚举,时间复杂度是O(n*k),超时.
最好是找一个类似二叉树搜索树的结构,可以在O(logn)的时间复杂度内完成删除和插入操作,multiset容器是典型的红黑树
结构,可以自动对元素进行排序,而且允许有重复值的出现.思路是,枚举每个数字,即窗口右边移动,若超过k,则需要把左边界
值进行删除.

方法二:
优先队列priority_queue,即最大堆,利用pair()存储当前的元素和位置,在枚举数组中的每个元素时,若优先队列中最大的元素此时不在窗口
中,则进行移除,判断方法就是将队首的元素pair的second位置与i-k进行比较,小于等于就进行删除,然后进行增加元素.
此时看到i>=k-1时,说明窗口大小正好是k,将最大值加入ans数组中.

方法三:
双端队列deque,保存元素的下标,枚举整个数组,若首元素是i-k,窗口右边移动一位,则移除队首元素,然后比较队列中末尾的元素
与将要加入元素的大小,若小的话则移除队尾元素,然后将队首元素加入ans数组中.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <deque>
#include <queue>//优先队列

using namespace std;

class Solution{
public:
    vector<int> maxSlidingwindow(vector<int>& nums,int k){
        vector<int> ans;
        /*超出时间限制
        for(int i=0;k+i<=nums.size();++i){
            int board=INT_MIN;
            for(int j=i;j<k+i;j++){
                board=max(board,nums[j]);
            }
            ans.push_back(board);
        }
        */
        multiset<int> res;
        for(int i=0;i<nums.size();i++){
            res.insert(nums[i]);
            cout<<i<<endl;
            if(res.size()==k){
                //cout<<nums[i-k+1]<<"  "<<*res.rbegin()<<endl;
                ans.push_back(*(--res.end()));/*或者*res.rbegin()*/
                //res.erase(res.lower_bound(nums[i-k+1]));/*返回指向大于或等于某值的第一个元素的迭代器*/
                res.erase(res.find(nums[i-k+1]));/*不能只用erase(nums[i-k+1]),因为有重复值*/
            }
        }
        return ans;
    }

    //优先队列
    vector<int> maxSlidingwindow1(vector<int>& nums,int k){
        vector<int> ans;
        priority_queue<pair<int,int>> res;//最大堆
        for(int i=0;i<nums.size();i++){
            while(!res.empty()&&res.top().second<=i-k){
                res.pop();
            }
            res.push({nums[i],i});
            if(i>=k-1){
                ans.push_back(res.top().first);
            }
        }
        return ans;
    }
    //双端队列
    vector<int> maxSlidingwindow1(vector<int>& nums,int k){
        vector<int> ans;
        deque<int> res;
        for(int i=0;i<nums.size();++i){
            //满足i-k
            if(!res.empty()&&res.front()==i-k)
               res.pop_front();
            //队尾元素小于新加入的
            while(!res.empty()&&nums[res.back()]<nums[i])
               res.pop_back();

            res.push_back(i);

            if(i+1>=k){
                ans.push_back(nums[res.front()]);
            }
        }
        return ans;
    }
};

int main(int argc,char* argv[]){
    vector<int> nums={1,3,1,2,0,5};//{1,3,-1,-3,5,3,6,7};
    const int k=3;
    vector<int> ans=Solution().maxSlidingwindow(nums,k);
    for(auto& i:ans){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
