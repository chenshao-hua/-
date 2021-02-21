/*
You are given a series of video clips from a sporting event that lasted T seconds.These video
clips can be overlapping with each other and have varied lengths.
Each video clip clips[i] is an interval:it starts at time clips[i][0] and ends at time
clips[i][1].We can cut these clips into segments freely:for example,a clip[0,7] can be cut into
sgements [0,1]+[1,3]+[3,7].
Return the minimum number of clips needed so that we can cut the clips into segments that cover
the entire sporting event ([0,T]).If the task is impossible,return -1.

Example 1:
Input:clips=[[0,2],[4,6],[8,10],[1,9],[1,5],[5,9]],T=10
Output:3
Explanation:
We take the clips [0,2],[8,10],[1,9];a total of 3 clips.Then,we can reconstruct teh sporting
event as followes:we cut [1,9] into segments [1,2]+[2,8]+[8,9].
Now we have segments [0,2]+[2,8]+[8,10] which cover the sporting event [0,10].

Example 2:
Input:clips=[[0,1],[1,2]],T=5
Output:-1
Explanation:
We can't cover [0,5] with only [0,1] and [1,2].

Example 3:
Input:clips=[[0,1],[6,8],[0,2],[5,6],[0,4],[0,3],[6,7],[1,3],[4,7],[1,4],[2,5],[2,6],[3,4]
            ,[4,5],[5,7],[6,9]],T=9
Output:3
Explanation:
We can take clips [0,4] [4,7], and [6,9].

Example 4:
Input:clips=[[0,4],[2,8]],T=5
Output:2
Explanation:
Notice you can have extra video after the event ends.

Constraints:
(1)1<=clips.length<=100
(2)0<=clips[i][0]<=clips[i][1]<=100
(3)0<=T<=100

题目大意:
给定一定序列视频片段的数组clips,这些片段来自于持续T秒的体育视频.将某些片段进行拼接,判断是否能构成整个运动过程的
时间段[0,T],若存在则返回最小数目的片段,否则为-1.注意这些片段允许重复交叉.

解题思路:
方法1:
贪心算法
先按照起始时间给片段进行排序,然后设置几个变量,lastend表示记录上一次用到的片段可以达到的位置,maxend表示当前
时间的片段可以到达的最大位置,i表示当前片段所在的索引.先进行循环,判断依据是end<T,再进行二次循环判断,选取最大的
maxend,若当前片段的起始时间满足<=lastend,则对maxend进行更新,直到选出最大的区间.然后判断lastend是否等于maxend,
若相等则出现断层,直接返回-1.否则更新lastend等于maxend,结果count+1,进入下一次循环,直到不满足条件.


方法2:
哈希map+动态规划
先利用哈希map存储res,默认key升序排序.key对于的是clips[i][0],value对应的是clips[i][1].先进行筛选,
这样就保留同key的value存储最长的片段,需要加if进行判断.因为clips[i][j]不大于100,片段不超过100.
所以dp设置初始化为101个片段和初始值为101.并将dp[0]设置为0,然后枚举res片段,并且枚举该片段内的所有时间点,
dp满足:dp[i]=min(dp[i],dp[r.first]+1)来更新其dp值.

方法3:
动态规划
不要map存储,直接对clips进行排序,然后dp就ok.
*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        map<int,int> res;
        for(const auto& clip:clips){
            if(res.count(clip[0])&&res[clip[0]]>clip[1]){
                continue;
            }
            res[clip[0]]=clip[1];
        }
        vector<int> dp(101,101);
        dp[0]=0;
        for(auto& r:res){
            for(int i=r.first+1;i<=r.second;i++){
                dp[i]=min(dp[i],dp[r.first]+1);
            }
        }
        return dp[T]==101?-1:dp[T];
    }
     int videoStitchingOne(vector<vector<int>>& clips, int T) {
         //count计数片段,i片段的索引位置,lastend记录上一次的最大结束时间,maxend表示当前片段的最大结束时间
         int count=0,n=clips.size(),i=0,lastend=0,maxend=0;
         sort(clips.begin(),clips.end());
         while(lastend<T){
             while(i<n&&clips[i][0]<=lastend){
                 maxend=max(maxend,clips[i++][1]);
             }
             if(lastend==maxend)
                 return -1;
             lastend=maxend;//更新当前最大位置
             count++;
         }
         return count;
     }
};

int main(int argc,char* argv[]){
    vector<vector<int>> clips={{0,4},{2,8}};//{{0,2},{4,6},{8,10},{1,9},{1,5},{5,9}};
    int T=8;//10;
    cout<<Solution().videoStitching(clips,T)<<endl;
    cout<<Solution().videoStitchingOne(clips,T)<<endl;
    return 0;
}