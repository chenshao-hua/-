/*
从x轴开始,给出一个数组,数组里面的数字代表从(0,0)开始,宽度为1个单位,
高度为数组元素的值.如果下雨了,这样一个容器能装多少水.

示例 1

Input:[0,1,0,2,1,0,3,2,1,2,1]
Output:6

解题思路:
每个数组里的元素值可以想象成一个左右都有壁的圆柱桶.示例中第5个元素为1,当
前左边最大的元素是2,因此值为2高度的水会装满右边1的上面(因为想象成了左右都有
桶壁).这道题可以利用双指针的算法,分别从左边、右边开始扫描,并设置两个临时变量
记录左边、右边的最大高度.遍历扫描数组元素的过程中,如果左指针的高度比右指针
的高度小,就不断的移动左指针,否则移动右指针.循环的终止条件就是左右指针碰上以后
就结束.只要数组中的元素的高度比保存的局部最大高度小,就累加res的值,否则更新
局部最大值,最终解就是res的值.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int traprain(vector<int>& rain){
        int left=0,right=rain.size()-1,maxleft=0,maxright=0,area=0;
        while(left<=right){
            if(rain[left]<=rain[right]){
                if(rain[left]>=maxleft){
                    maxleft=rain[left];
                }else{
                    area+=maxleft-rain[left];          
                }
                left++;
            }else{
                if(rain[right]>=maxright){
                    maxright=rain[right];
                }else{
                    area+=maxright-rain[right];
                }
                right--;
            }
        }
        return area;
    }
};
int main(int argc,char* argv[]){
    vector<int> rain={2,0,1,0,3,1,0,2,2,0,5};
    cout<<Solution().traprain(rain)<<endl; 
    return 0;
}