/*
不出现重复的元素
方法1:
利用unordered_set容器
方法2:
排序+双指针
*/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution{
public:
    vector<int> intersection1(vector<int>& nums1,vector<int>& nums2){
        vector<int> ans;
        if(nums1.empty()||nums2.empty())
            return ans;
        unordered_set<int> board;
        for(auto& num:nums1)
            board.insert(num);
        for(auto& num:nums2){
            if(board.count(num)){
                ans.emplace_back(num);
                board.erase(num);
            }
        }
        return ans;
    }

    vector<int> intersection2(vector<int>& nums1,vector<int>& nums2){
        vector<int> ans;
        if(nums1.empty()||nums2.empty())
            return ans;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int i=0,j=0,n=nums1.size(),m=nums2.size();
        while(i<n&&j<m){
            if(nums1[i]==nums2[j]){
                /*唯一性*/
                if(ans.empty()||ans.back()!=nums1[i]){
                    ans.push_back(nums2[j]);
                }           
                i++;
                j++;
            }else if(nums1[i]>nums2[j]){
                j++;
            }else{
                i++;
            }
        }
        return ans;
    }
};
int main(int argc,char* argv[]){
    vector<int> nums1={1,2,2,1},nums2={2,2};
    vector<int> ans=Solution().intersection2(nums1,nums2);
    for_each(ans.begin(),ans.end(),[&](const int& num){
        cout<<num<<" ";
    });
    cout<<endl;    
    return 0;
}