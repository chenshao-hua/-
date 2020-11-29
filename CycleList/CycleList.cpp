/*
leetcode142:
给定一个链表，返回链表开始入环的第一个节点.如果链表无环，则返回null.
*/
#include <iostream>

using namespace std;
typedef struct list{
    list* next;
    int data;
}listnode;

class Solution{
public:
    listnode* detectCycle(){
        listnode* fast=head;
        listnode* slow=head;

        /*获取首次相遇时候,slow的位置*/
        while(fast!=nullptr&&fast->next!=nullptr){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow)
               break;
        }
        
        /*如果快指针走到尽头，不存在环*/
        if(fast==nullptr||fast->next==nullptr)
            return nullptr;

        /*快指针重新出发，相遇位置就是入口位置*/
        fast=head;
        while(fast!=slow){
            fast=fast->next;
            slow=slow->next;
        }
        return slow;
    }
private:
    listnode* head;
};