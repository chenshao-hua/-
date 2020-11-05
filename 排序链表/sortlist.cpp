#include <iostream>
using namespace std;

typedef struct ListNode{
    int data;
    ListNode *next;
    ListNode(const int& x):data(x),next(nullptr){}
}Node;


class List{
public:
    List(){
        CreateList();
    }
    ~List(){
        ClearList();
    }
    void TailInsert(const int & x);            //从链表尾部插入一个节点
    void Print(); //打印链表
    Node* GetList(){
        return head;
    }

#if 0
    void HeadInsert(const int& x);             //从链表头部插入一个节点
    void Insert(const int& n,const int& x);    //指定位置插入节点
    void Erase(const int& n);                  //删除指定位置的节点
    void Modify(const int& findx,const int& x);  //修改数据
    void Update(const int& n,const int& x);        //修改指定位置的节点
    void Reverse();   //翻转链表
#endif
    
    Node* sortlist(Node* first){
        //递归结束条件
        if(first==nullptr||first->next==nullptr)
            return first;
        
        //找到链表中间节点并断开链表，递归下探
        Node* midNode=middleNode(first);
        Node* rightNode=midNode->next;
        midNode->next=nullptr;

        Node* left=sortlist(first);
        Node* right=sortlist(rightNode);

        //当前层业务操作（合并有序链表）
        return mergeTwoLists(left,right);
    }
    

private:
    Node* head; //头节点 
    Node* sentry; //存储链表
    void CreateList(); //创建链表
    void ClearList();  //删除链表

    //找到链表中间节点
    Node* middleNode(Node* first){
        if(first==nullptr||first->next==nullptr)
            return first;
        
        Node* slow=first;
        Node* fast=first->next->next;

        while(fast!=nullptr&&fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }

    //合并两个有序链表
    Node* mergeTwoLists(Node* L1,Node* L2){ 

        sentry=new Node(0); //存储合并的有序链表
        Node* current=sentry;
        while(L1!=nullptr&&L2!=nullptr){
            if(L1->data<L2->data){
                current->next=L1;
                L1=L1->next;
            }else{
                current->next=L2;
                L2=L2->next;
            }
            current=current->next;
        }

        current->next=L1!=nullptr?L1:L2;
        return sentry->next;
    }

 #if 0   
    Node* find(const int& findx);//查找数据所在的节点
 #endif   
};

//创建链表
void List::CreateList(){
    head=new Node(0);
}

//删除链表
void List::ClearList(){
    Node *temp=head;
    while(temp){
        Node *tempnext=temp->next;
        delete temp;
        temp=tempnext;
    }
    Node *temp_sen=sentry;
    while(temp_sen){
        Node *temp_next=temp_sen;
        delete temp_sen;
        temp_sen=temp_next;
    }
}

//从尾部插入
void List::TailInsert(const int& x){
    Node *temp=head;
    Node *p=new Node(x);
    if(temp==nullptr){
        cout<<"链表不存在"<<endl;
        return;
    }
    while(temp->next){
        temp=temp->next;
    }
    temp->next=p;
}

void List::Print(){
    if(head==nullptr){
        cout<<"链表不存在"<<endl;
        return;    
    }
    Node *temp=head->next;
    while(temp){
        cout<<temp->data<<"  ";
        temp=temp->next;
    }
    cout<<endl;
}


int main(int argc,char* argv[]){
     List sortList;
     int nums[]={3,-2,4,6,-1,5,-1,7,-9};
     int n=sizeof(nums)/sizeof(nums[0]),i=0;
     while(i<n)
        sortList.TailInsert(nums[i++]);    
     sortList.Print();
     
     Node* result=sortList.sortlist(sortList.GetList()->next); //去除头节点
     while(result){
        cout<<result->data<<"  ";
        result=result->next;
     }
     cout<<endl;
     return 0;
}