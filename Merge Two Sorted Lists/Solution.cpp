/*
方法1:迭代法
利用两个指针分别指向两个链表的头部,然后逐次进行比较,并满足条件的进行+1即可.
最后再链接没有遍历完的链表即可.时间复杂度为:O(n),空间复杂度为O(1).

方法2:递归
*/
#include <iostream>

using namespace std;

struct LinkNode{
    int val;
    LinkNode* next;
    LinkNode():val(0),next(nullptr){}
    LinkNode(int val):val(val),next(nullptr){}
    LinkNode(int val,LinkNode* next):val(val),next(next){}
};

class Solution{
public:
    LinkNode* MergeTwoLinkNode(LinkNode* root1,LinkNode* root2){
        if(!root1||!root2)
            return root1?root1:root2;
        LinkNode *pre1=root1,*pre2=root2;
        LinkNode root,*tail=&root;//不清楚root1和root2首节点谁大,需设置一个初始节点,不能直接使用
        //它们赋值
        while(pre1!=nullptr&&pre2!=nullptr){
            if(pre1->val<=pre2->val){
                tail->next=pre1;
                pre1=pre1->next;
            }else{
                tail->next=pre2;
                pre2=pre2->next;
            } 
            tail=tail->next; 
        }
        tail->next=(pre1?pre1:pre2);
        return root.next;//保存链表,去除栈上的root
    }
    LinkNode* MergeTwoLinkNodeOne(LinkNode* root1,LinkNode* root2){
        if(root1==nullptr){
            return root2;
        }else if(root2==nullptr){
            return root1;
        }else if(root1->val<root2->val){
            root1->next=MergeTwoLinkNodeOne(root1->next,root2);
            return root1;
        }
        root2->next=MergeTwoLinkNodeOne(root1,root2->next);
        return root2;
    }
};