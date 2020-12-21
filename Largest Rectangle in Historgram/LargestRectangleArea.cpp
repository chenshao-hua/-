/*
Given n non-negative integers representing the histogram's bar height where the width of 
each bar is 1,find the area of largest rectangle in the histogram.
Above is a histogram where width of each bar is 1,given height=[2,1,5,6,2,3]
The largest rectangle is shown in the shaded area,which haa area=10 unit.

Example 1:
Input:[2,1,5,6,2,3]
Output:10

解题思路:
方法1：
暴力以height为标准进行枚举,时间超时.
方法2:
利用单调递增栈的思想.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;
class Solution{
public:
#if 0
    int largestRectangleArea(vector<int>& heights){
        if(heights.empty())
           return 0;
        int area=0,h=0,left,right;
        for(auto i=0;i<heights.size();i++){
            left=i,right=i,h=heights[i];
            while(left>0&&heights[i]<=heights[left-1]){left--;};
            while(right<heights.size()-1&&heights[i]<=heights[right+1]){right++;};
            area=max(area,(right-left+1)*h);
        }
        return area;
    }
#endif
    int largestRectangleArea(vector<int>& heights){
        if(heights.empty())
           return 0;
        heights.push_back(-1);/*这样可以计算heights数组所有的元素*/
        stack<int> des;
        int area=0,left;
        for(auto i=0;i<heights.size();i++){
            if(des.empty()||heights[des.top()]<=heights[i]){
                des.push(i);
            }else{
                while(!des.empty()&&heights[des.top()]>heights[i]){
                    left=des.top();
                    des.pop();
                    area=max(area,(i-left)*heights[left]);
                }
                des.push(left);/*入栈*/
                heights[left]=heights[i];/*记忆元素*/
            }
        }
        return area;
    }
};

int  main(int argc,char* argv[]){
    vector<int> heights={6,7,5,2,4,5,9,3};/*0、1、2、3、4、5、6、7*/
    cout<<Solution().largestRectangleArea(heights)<<endl;
    return 0;
}