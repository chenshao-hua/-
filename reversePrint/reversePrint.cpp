/*
剑指Offer 06:从尾到头打印链表
输入一个链表的头节点,从尾到头反过来返回每个节点的值(用数组返回)

示例 :
Input:head=[1,3,2]
Output:[2,3,1]

解题思路:
先定义链表,获取链表末尾,并删除;
*/
#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Solution{
    public:
    vector<int> reversePrint(list<int> head){
        if(head.empty()){
            cout<<"链表为空.."<<endl;
            return {};
        }
        vector<int> result;
        auto n=head.size();
        while(n--){
            result.push_back(head.back());
            head.pop_back();
        };
        return result;
    }
};
int main(int argc,char* argv[]){
    list<int> head;
    head.push_back(1);
    head.push_back(3);
    head.push_back(2);
    vector<int> result=Solution().reversePrint(head);
    for(auto& res:result)
        cout<<res<<" ";
    cout<<endl;
    return 0;
}