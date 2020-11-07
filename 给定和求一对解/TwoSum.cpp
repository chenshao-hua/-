/*
题目描述：
在一个增序的整数数组里面找到两个数，使得它们的和为给定值。已知有且只有一对解。

示例:
Input:numbers=[2,7,11,15],target=9
Output:[1,2]

解题思路：
因为数组已经排序好，可以采用方向相反的双指针来寻找这两个元素，一个初始指向最小的元素，即数组
最左边，向右遍历；一个初始指向最大的元素，即数组最右边，向左遍历。
（1）若两个指针指向元素的和等于给定值，那么它们就是我们要的结果；
（2）若两个指针指向元素的和小于给定值，则把左边的指针右移动一位，使得当前的和增加一点；
（3）若两个指针指向元素的和大于给定值，则把右边的指针左移动一位，使得当前的和减少一点；
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    Solution(vector<int>& _numbers,const int& _target):numbers(_numbers),target(_target){}
    vector<int> TwoSum(){
        int L=0,R=numbers.size()-1,sum;
        while(L<R){
            sum=numbers[L]+numbers[R];
            if(sum==target)
                 break;
            else if(sum<target)
                 L++;
            else 
                 R--;
        }
        return vector<int>{L+1,R+1};
    }

private:
    vector<int> numbers;
    int target;
};

int main(int argc,char* argv[]){
    vector<int> numbers={2,7,11,15};
    Solution solu(numbers,9);
    vector<int> position=solu.TwoSum();
    cout<<position[0]<<"  "<<position[1]<<endl;
    return 0;
}