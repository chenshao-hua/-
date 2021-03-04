#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isStraight(vector<int>& nums){
        set<int> res;
        int MaxNum=0,MinNum=0;
        for(auto& n:nums){
            if(n==0) continue;
            MaxNum=max(MaxNum,n);
            MinNum=min(MinNum,n);
            if(!res.insert(n).second) return false;
        }
        return MaxNum-MaxNum<=4;
    }
      bool isStraightOne(vector<int>& nums){
          
          sort(nums.begin(),nums.end());
          int n=0;//统计大小王的个数
          for(int i=0;i<4;i++){
              if(nums[i]==0) n++;
              if(nums[i]==nums[i+1]) return false;//判断重复
          }
          return nums[4]-nums[n]<=4;
      }
};

int main(int argc,char* argv[]){
    vector<int> nums={0,1,2,5,0};

    return 0;
}