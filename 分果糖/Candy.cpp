/*题目描述:
一群孩子站成一排，每一个孩子有自己的评分，现在需要给这些孩子发糖果，规则是如果一个孩子
的评分比自己身旁的一个孩子要高，那么这个孩子就必须得到比身旁孩子更多的糖果，而且每一个
孩子至少要有一个糖果，求解最少需要多少个糖果。

示例：
输入一个数组，表示孩子的评分，输出是最少糖果的数量。
Input:[1,0,2]
Output:5
在这个样例中，最少的糖果分法是[2,1,2]

解题思路：
贪心算法，只需要两次遍历。把所有孩子的糖果数初始化为1；先从左往右遍历一遍，如果右边孩子
的评分比左边的高，则右边孩子的糖果更新为左边的孩子糖果数加1，这样可以确保右边孩子获得糖果
达到局部最优；再从右往左边遍历一遍，如果左边孩子的评分比右边的高，且左边孩子当前的糖果
数小于右边孩子的糖果数，则左边孩子的糖果数更新为右边孩子糖果数加1，这样可以确保左边孩子
获得糖果数达到局部最优。这里的贪心策略，在每次进行遍历中，只考虑并更新相邻一侧的大小关系。
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution{
public:
    Solution(vector<int>& _ratings):ratings(_ratings){}
    int candy(){
        int size=ratings.size();
        if(size<2)
           return size;
        
        /*从左到右遍历*/
        vector<int> num(size,1);
        for(int i=1;i<size;i++){
            if(ratings[i]>ratings[i-1]) /*左边孩子的评分低于右边孩子评分*/
               num[i]=num[i-1]+1;
        }
        
        /*从右到左遍历*/
        for(int j=size-1;j>0;j--){
            if(ratings[j]<ratings[j-1]) /*右边孩子的评分低于左边孩子评分*/
               num[j-1]=max(num[j-1],num[j]+1);
        }
        return accumulate(num.begin(),num.end(),0);
    }
private:
    vector<int> ratings;
};

int main(int argc,char* argv[]){
    vector<int> rate={1,0,2,4};
    Solution so(rate);
    cout<<so.candy()<<endl;
    return 0;
}