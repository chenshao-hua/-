/*
给定一个整数数组nums,其中恰好有两个元素只出现一次,其余元素均出现两次.找出只出现一次的那两个元素.
Example 1:
Input:[1,2,1,3,2,5]
Output:[3,5]

解题思路:
方法一:
先排序,每次取两个,用数组存储结果,注意若出现相邻两个不等,则进行加1,进入下一次循环;
方法二:
用关联型容器存储,set或者map;
方法三:
位运算,对二进制数字进行分组,零和非零,则这两个数字就会落在这两个组里面.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution{
public:
    /*取两个*/
    vector<int> singlenumber(vector<int>& nums){
        int n=nums.size();
        vector<int> ans;
        sort(nums.begin(),nums.end());
        for(auto i=1;i<n;){
            if(nums[i-1]!=nums[i]){
                ans.push_back(nums[i-1]);
                i++;
                continue;
            }
            i+=2;             
        }
        if(ans.size()!=2){
            ans.push_back(nums[n-1]);
        }
        return ans;
    }

    /*关联容器*/
    vector<int> singlenumbers(vector<int>& nums){
        int n=nums.size();
        set<int> ans;
        for(auto num:nums){
            if(ans.find(num)!=ans.end()){
                ans.erase(num);
            }else{
                ans.insert(num);
            }
        }
        vector<int> res;
        copy(ans.begin(),ans.end(),inserter(res,res.begin()));
        return res;
    }

    /*位运算*/
    vector<int> bitsinglenumber(vector<int>& nums){
        vector<int> res(2,0);
        int board=0;
        for(auto& num:nums)
           board^=num;/*异或值*/
        int right=board&(-board);/*求二个数中二进制中不同的位所在的位置,保留最右边的1*/
        cout<<right<<endl;
        for(auto& i:nums){
            /*进行分组:0、非0两组*/
            if((right&i)==0){
                res[0]^=i;
            }else{
                res[1]^=i;
            }
        }   
        return res;
    }
};
int main(int argc,char* argv[]){
    vector<int> nums={1,2,1,3,2,5};
    vector<int> ans=Solution().bitsinglenumber(nums);
    for_each(ans.begin(),ans.end(),[&](const int& num){
        cout<<num<<" ";
    });
    cout<<endl;
    return 0;
}