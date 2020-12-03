#include <iostream>

using namespace std;

class ListNode{
public:
    int val;
    ListNode* next;
    ListNode(int x){val=x;};
};

class Solution{
public:
    ListNode* reverseList(ListNode* head){
        if(head==nullptr||head->next==nullptr)
           return head;
        ListNode* ans=nullptr;/*申请一个节点,用来存储反向链表*/
        ListNode* cur=head;/*首节点,不考虑头节点*/
        /*头插法*/
        while(cur!=nullptr){
            ListNode* temp=cur->next;
            cur->next=ans;
            ans=cur;/*指针后移*/
            cur=temp;/*指针后移,处理下一个节点*/
        }
    }
};