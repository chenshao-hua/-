#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode():val(0),next(nullptr){}
    ListNode(int x):val(x),next(nullptr){}
    ListNode(int x,ListNode* next):val(x),next(next){}
};

class Solution{
public:
     Solution(){
         root=new ListNode(0);//利用指针,在堆上开辟空间,不能用栈上的局部变量返回地址.
         tmp=nullptr;
     }
     ListNode* mergeKLists(vector<ListNode*>& lists){
         if(lists.empty()) return nullptr;
         vector<int> res;
         for(auto& list:lists){
             while(list){
                 res.push_back(list->val);
                 list=list->next;
             }
         }
         sort(res.begin(),res.end()); 

         ListNode* head=root; 
         for(int i=0;i<res.size();i++){ 
             tmp=new ListNode(res[i]);  
             head->next=tmp;
             head=tmp;
         }  
         return root->next;//调试了很久,返回的根节点不存储值才行
     }

private:
     ListNode* root; 
     ListNode* tmp;
};

//方法二:归并排序
class SolutionOne{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists){
        return merge(lists,0,lists.size()-1);
    }
    ListNode* merge(vector<ListNode*>& lists,int l,int r){
        if(l==r) return lists[l];
        if(l>r) return nullptr;
        int mid=(l+r)>>1;
        return MergeTwoLists(merge(lists,l,mid),merge(lists,mid+1,r));
    }

    ListNode* MergeTwoLists(ListNode* l,ListNode* r){
        if(l==nullptr||r==nullptr)
           return l?l:r;
        ListNode head,*tail=&head;
        ListNode *pre1=l,*pre2=r;
        while(pre1&&pre2){
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
        return head.next;
    }
};

//方法三:优先队列
class SolutionTwo{
public:
    ListNode* MergeKLists(vector<ListNode*>& lists){
        if(lists.empty()) return nullptr;
        //priority_queue默认三个参数
        //Type就是数据类型,Container就是容器类型(Container必须是用数组实现的容器,
        //比如vector,deque等等,但不能用 list.STL里面默认用的是vector),Functional 就是比较的方式。
        priority_queue<ListNode*,vector<ListNode*>,Comp> q;
        for(ListNode* list:lists){
            if(list){
                q.push(list);
            }
        }
        ListNode root;
        ListNode* dummy=&root,*cur=dummy;
        while(!q.empty()){
            cur->next=q.top();
            q.pop();
            cur=cur->next;
            if(cur->next){
                q.push(cur->next);
            }
        }
        return root.next;
    }

    struct Comp{
        bool operator()(ListNode* l1,ListNode* l2){
            return l1->val>l2->val; //最小堆
        }
    };
};
int main(int argc,char* argv[]){

    return 0;
}