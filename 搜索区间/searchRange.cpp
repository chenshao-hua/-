/*起始位置、终止位置二分搜索，传入数组nums与目标值target，函数返回数组中的第一个等于目标值的元素下标*/

#include <iostream>
#include <vector>

using namespace std;
class Solution{
public:
    vector<int> searchRange(vector<int>& nums,int target){
        vector<int> range;

        range.push_back(left_position(nums,target));
        range.push_back(right_position(nums,target));
        return range;
    }

    int left_position(vector<int>& nums,int target){
        int left=0;//设置搜索区间的左端点为0
        int right=nums.size()-1;//设置搜索区间的右端点
        //左端点小于等于右端点，进行二分查找
        while(left<=right){
            int mid=(left+right)/2;
            if(nums[mid]==target){
                if(mid==0||nums[mid-1]<target){//mid为数组的第一个元素或者mid的前一个元素小于target
                    return mid;
                }
                right=mid-1;//否则设置right等于mid减1
            }
            else if(nums[mid]>target)
                right=mid-1;//设置right等于mid减1
            else if(nums[mid]<target)
                left=mid+1; //设置left等于mid加1
        }
        return -1;  //不存在目标元素
    }

    int right_position(vector<int>& nums,int target){
        //初始化搜索区间的左右端点
        int left=0;
        int right=nums.size()-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(nums[mid]==target){
                //后面的元素大于target或者mid为数组最后一个元素
                if(mid==nums.size()-1||nums[mid+1]>target){
                    return mid;
                }
                left=mid+1;
            }
            else if(nums[mid]>target)
                right=mid-1;
            else if(nums[mid]<target)
                left=mid+1;
        }
        return -1;
    }
};
int main(int argc,char* argv[]){
    //设置测试数据
    int test[]={1,6,6,7,8,8,8,9,9,10};
    vector<int> nums;
    Solution sonums;
    for(int i=0;i<sizeof(test)/sizeof(test[0]);i++)
        nums.push_back(test[i]);
    
    vector<int> range=sonums.searchRange(nums,6);
    printf("[%d,%d]\n",range[0],range[1]);
    return 0;
}