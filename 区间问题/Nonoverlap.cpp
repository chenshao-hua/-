/*题目描述：
给定多个区间，计算让这些区间互不重叠所需要移除区间的最少个数。起止相连不算重叠。

示例：
输入是一个数组，数组由多个长度固定为2的数组组成，表示区间的开始和结尾，输出一个整数，
表示需要移除的区间数量。
Input:[[1,2],[2,4],[1,3]]
Output:1
在示例中，可以移除区间[1,3]，使得剩余的区间[[1,2],[2,4]]互不重叠。

解题思路：
在选择要保留区间时，区间的结尾十分重要：选择的区间结尾越小，余留给其他区间的空间就越大，
就越能保留更多的区间。因此，采用贪心算法：优先保留结尾小且不相交的区间。
实现方法：先把区间按照结尾的大小进行增序排序，每次选择结尾最小且和前一个选择的区间不重叠
的区间。

注意：需要根据实际情况判断按区间开头排序还是按照区间结尾排序。
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
     Solution(vector<vector<int>>& _intervals):intervals(_intervals){}
     int eraseOverlapIntervals(){
         if(intervals.empty())
             return 0;
         sort(intervals.begin(),intervals.end(),[](vector<int> a,vector<int> b){
             return a[1]<b[1];
         });
         int total=0,prev=intervals[0][1],i=1;
         while(i<intervals.size()){
             if(intervals[i][0]<prev)
                total++;
             else
                prev=intervals[i][1];
             i++;
         }
         return total;
     }
    //
private:
     vector<vector<int>>& intervals;
    
};

int main(int argc,char* argv[]){
    vector<vector<int>> intervals={{1,2},{1,3},{2,4},{2,3}};
    Solution solu(intervals);
    cout<<solu.eraseOverlapIntervals()<<endl;
    return 0;
}