/*
题目描述:
给定一个数组,数组每个位置的值表示该位置的权重,要求按照权重的概率去随机采样.

Example 1:
Input:weights=[1,3],actions=["pickIndex","pickIndex","pickIndex"]
Output:[0,1,1]
在这个样例中,每次选择的位置都是不确定的,但选择第0个位置的期望为1/4,选择第1个位置的期望为3/4.

解题思路:
可以先使用partial_sum求前缀和(即到每个位置为止前所有数字的和),这个结果对于正整数数组是单调递增的.
每当需要采样时,可以先随机产生一个数字,然后使用二分法查找其在前缀和的位置,以模拟加权采样的过程.这里的
二分法采用lower_bound实现.
以样例为例,权重数组[1,3]的前缀和为[1,4].如果我们随机生成的数字为1,那么lower_bound返回的位置为0;
如果随机生成的数字是2、3、4,则lower_bound返回的位置为1.
*/

#include <iostream>
#include <vector>
#include <utility>   /*move*/
#include <numeric>   /*partial_sum*/
#include <algorithm> /*lower_bound二分查找*/
#include <random>  /*uniform_int_distribution随机数类模板*/
#include <time.h>

/*rand()%n产生从0到n-1的随机数*/
using namespace std;

class Solution{
private:
    vector<int> sums;
public:
    Solution(vector<int> weights):sums(std::move(weights)){
        partial_sum(sums.begin(),sums.end(),sums.begin());
    }
    int pickIndex(){

        int pos=(rand()%sums.back())+1;
        return lower_bound(sums.begin(),sums.end(),pos)-sums.begin();
        //default_random_engine en(static_cast<unsigned int>(time(nullptr)));
        //uniform_int_distribution<int> pos{1,sums.back()};
        //return lower_bound(sums.begin(),sums.end(),pos(en))-sums.begin();
    }
    
};
int main(int argc,char* argv[]){
    vector<int> weights={1,3};
    //vector<string> actions={"pickIndex","pickIndex","pickIndex"};
    cout<<Solution(weights).pickIndex()<<endl;
    return 0;
}