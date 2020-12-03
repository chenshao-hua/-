/*
剑指Offer 24:反转链表
定义一个函数,输入一个链表的头节点,反转该链表并输出反转后链表的头节点.

示例 :
Input:1->2->3->4->5->NULL
Output:5->4->3->2->1->NULL

解题思路:
利用list容器便可以实现,已知节点head,算法思路是声明一个空的节点result,
用临时变量保存head的下一个节点,然后将当前节点的下一个节点指向result的前一个
节点,最后将前一节点后移,head节点后移
*/
#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

class Solution{
public:
    list<int> reverseList(list<int>& head){
        if(head.empty()||head.size()==1)
            return head;
        auto it=head.begin();
        list<int> ans;
        for(;it!=head.end();it++){
            ans.push_front(*it);
        }
        return ans;
    }
};

int main(int argc,char* argv[]){
    list<int> head;
    head.push_back(1);
    head.push_back(2);
    head.push_back(3);
    head.push_back(4);
    head.push_back(5);
    Solution so;
    list<int> ans=so.reverseList(head);
    for_each(ans.begin(),ans.end(),[](int& num){
        cout<<num<<" ";
    });
    cout<<endl;
    return 0;
}