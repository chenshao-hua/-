/*
题目描述：
给定一个无重复数字的整数,求其所有的排列方式.

示例：

Input:[1,2,3]
Output:[[1,2,3],[1,3,2],[2,1,3],[2,3,1,[3,1,2],[3,2,1]]

解题思路:
怎样输出所有的排列方式呢？对于每一个当前位置i,可以将其与之后的位置进行交换,然后继续处理位置i+1,
直到处理到最后的一位.为了防止每次遍历都需要新建一个子数组储存位置i之前已经交换号的数字,可以利用
回溯法.只要对原数组进行修改,在递归完成后再修改回来.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    Solution(vector<int>& _nums):nums(_nums){}
    vector<vector<int>> permute(){
        vector<vector<int>> ans;
        backtracking(nums,0,ans);
        return ans;
    }
private:
    vector<int> nums;
    void backtracking(vector<int>& nums,int level,vector<vector<int>>& ans){
        if(level==nums.size()-1){
            ans.push_back(nums);
            return;
        }
        for(auto i=level;i<nums.size();i++){
            swap(nums[i],nums[level]); /*修改当前节点状态*/
            backtracking(nums,level+1,ans);
            swap(nums[i],nums[level]);/*返回当前节点状态*/
        }
    }
};

int main(int argc,char* argv[]){
    vector<int> nums{1,2,3};
    vector<vector<int>> result=Solution(nums).permute();
    for_each(result.begin(),result.end(),[](vector<int>& res){
        cout<<"[ ";
        for(auto& i:res){
            cout<<i<<" ";
        }
        cout<<"]"<<endl;
    });
    return 0;
}