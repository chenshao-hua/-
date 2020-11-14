/*
有n块石头分别在x轴的0,1,...,n-1位置，一致青蛙在石头0，想跳到石头n-1，如果青蛙
在第i块石头上，它最多可以向右跳距离ai，问青蛙能否跳到石头n-1？

示例1：
Input:a=[2,3,1,1,4]
Output:True

示例2：
Input:a=[3,2,1,0,4]
Output:False

解题思路：
这道题是存在性动态规划，
1.确定状态
（1）最后一步：若青蛙能跳到最后一块石头n-1，这一步是从石头i过来的，则需要满足两个
条件:
-青蛙可以跳到石头i；
-最后一步不超过跳跃的最大距离:n-1-i<=ai
那么我们需要知道青蛙能不能跳到石头i(i<n-1)，这是一个子问题，其状态为：F[j]表示青蛙
能不能跳到石头j;
2.转移方程
F[j]=OR(0<=i<j)(f[i]AND i+a[i]>=j)
OR代表只要一个满足,AND代表满足两个条件,其中o<=i<j表示枚举上一个跳到石头i,f[i]表示石头能不能跳到石头i,最后一步的距离不能
超过aj;
3.初始条件和边界情况
f[0]=true
4.计算顺序
f[1],f[2]....f[n-1],结果是f[n-1]

*/
#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    Solution(vector<int>& _nums):nums(_nums){}
    bool JumpGame(){
        int n=nums.size();
        vector<bool> canJump(n);
        canJump[0]=true;/*初始化*/

        for(int j=1;j<n;j++){
            canJump[j]=false;
            /*以前的石头i*/
            for(int i=0;i<j;i++){
                if(canJump[i]&&j-i<=nums[i]){
                    canJump[j]=true;
                    break;
                }
            }
        }
        return canJump[n-1];
    }
private:
    vector<int> nums;
};

int main(int argc,char* argv[]){
    vector<int> nums={2,3,1,0,4};
    Solution solu(nums);
    cout<<solu.JumpGame()<<endl;
    return 0;
}