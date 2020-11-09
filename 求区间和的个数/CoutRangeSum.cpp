/*
题目描述：
给定一个整数数组，返回区间和在[lower,upper]之间的个数，包含lower和upper，区间和S(i,j)
表示在nums中，位置从i到j的元素之和，包含i和j(i=<j)。

注意：
最直观的时间复杂度是O(n^2)，请在此基础上优化你的算法。

示例：
Input:nums=[-2,5,1],lower=-2,upper=2
Output:3
其中3个区间:[0,0],[2,2],[0,2]它们表示的和分别为:-2,-1,2

解题思路:
归并排序
（1）求区间和，一般先构建前缀和数组进行数据预处理，可以O(1)得到任意区间和；
（2）查找元素，一般先进行排序，利用单调性可以快速的缩减查找范围，减少时间复杂度；
（3）归并排序包含了两个过程：从上往下的分解：把当前区间一分为二，直至分解为若干个
长度为1的子数组。从下往上的合并：两个有序的子区域两两向上合并；
（4）对于本题，归并过程中，右区间中元素分别和左区间中元素的差即原数组的各区间和，利用
有序可以减少重复的比较操作；
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution{

public:
    Solution(vector<long long>& _nums,const int& _lower,const int& _upper):nums(_nums),lower(_lower),upper(_upper){}
    int coutRangeSum(){
        if(nums.empty())
           return 0;
        vector<long long> presum;//前缀和数组，[0,i]区间和
        long long pre=0;
        for(auto& num:nums){
            pre+=num;
            presum.emplace_back(pre);
        }
        int result=0;
        vector<long long> temp(nums.size());//用于合并两个有序数组的临时数组
        mergesort(presum,lower,upper,temp,0,nums.size()-1,result);
        
        return result;
    }

private:
    void mergesort(vector<long long>& presum,int& low,int& up,vector<long long>& temp,int left,int right,int& result){
        if(left==right){
            if(presum[left]>=low&&presum[left]<=up)
               result++;
            return;
        }
        int mid=left+(right-left)/2;
        mergesort(presum,low,up,temp,left,mid,result);//使得[left,mid]有序
        mergesort(presum,low,up,temp,mid+1,right,result);//使得[mid+1,right]有序

        //合并之前先进行统计
        int i=left;//i指向左区间
        int j_left=mid+1;
        int j_right=mid+1;//j_left、j_right指向右区间，i<j，相减得到区间和
        //i固定时，j越大差越大；j固定时，i越大差越小
        while(i<mid+1){
            while(j_left<=right&&presum[j_left]-presum[i]<low)//找到下限位置
                j_left++;
            j_right=j_left;
            while(j_right<=right&&presum[j_right]-presum[i]<=up){//找到上限位置
                j_right++;
                result++; //找到一对
            }
            i++;
        }

        //合并
        i=left;
        int j=mid+1,t=0;
        while(i<=mid&&j<=right){
            if(presum[i]<=presum[j])
                temp[t++]=presum[i++];
            else
                temp[t++]=presum[j++];
        }

        while(i<=mid)
            temp[t++]=presum[i++];
    
        
        while(j<=right)
            temp[t++]=presum[j++];

        t=0,i=left;
        while(i<=right)
            presum[i++]=temp[t++];
    }
private:
    vector<long long> nums;
    int lower,upper;
};

int main(int argc,char* argv[]){
    vector<long long> nums={-2,5,-6};
    Solution solu(nums,-2,2);
    cout<<solu.coutRangeSum()<<endl;
    return 0;
}