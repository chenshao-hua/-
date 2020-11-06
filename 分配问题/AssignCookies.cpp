/*分配问题*/
/*
题目描述：
有一群孩子和一堆饼干，每个孩子有一个饥饿度，每个饼干都有一个大小。每个
孩子只能吃最多一个饼干，且只有饼干的大小大于或等于孩子的饥饿度时，这个孩子才能
吃饱。求解最多有多少个孩子可以吃饱。

示例：
输入两个数组，分别代表孩子的饥饿度和饼干的大小。输出最多有多少孩子可以吃饱的数量。
Input:[1,2],[1,2,3]
Output:2
其中可以给这两个孩子喂[1,2],[1,3],[2,3]这样三种组合的任意一种。

解题思路：
因为饥饿度最小的孩子最容易吃饱。所以先考虑这个孩子。为了尽量使得剩下的饼干可以满足饥饿
度更大的孩子，所以应该把大于或等于这个孩子的饥饿度、且大小最小的饼干给这个孩子。满足了
这个孩子之后，再采用相同的策略，考虑剩下孩子里面饥饿度最小的孩子，直到没有满足条件的
饼干存在。
简而言之，这里采用的是贪算法，给剩余孩子里最小饥饿度的孩子分配最小的能饱腹的饼干。具体
实现方式，需要获取大小关系。首先对孩子和饼干分别排序。这样能够从饥饿度最小的孩子和大小
最小的饼干出发，计算有多少个对子可以满足条件。

注意：对数组或字符串排序是常见的操作，方便之后进行大小比较。
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
    Solution(vector<int>& _children,vector<int>& _cookies):children(_children),cookies(_cookies){}
    int findChildren(){
        /*升序排序*/
        sort(children.begin(),children.end());
        sort(cookies.begin(),cookies.end());
        int child=0,cookie=0;
        while(child<children.size()&&cookie<cookies.size()){
            if(children[child]<=cookies[cookie])
               child++;
            cookie++;
        }
        return child;
    }
private:
    vector<int> children;
    vector<int> cookies;
};

int main(int argc,char* argv[]){
    vector<int> children={1,2};
    vector<int> cookies={1,2,4};
    Solution solu(children,cookies);
    cout<<solu.findChildren()<<endl;
    return 0;
}