#include <iostream>
#include <vector>

using namespace std;

//根节点初始下标为1
class MaxHeap{
public:
    //获取最大值
    int top(){
        return heap[0];
    }
    
    //插入任意值,把新的数字放在最后一位,然后上浮
    void push(int k){
        heap.push_back(k);
        swim(heap.size()-1);//维持最大堆    
    }

    //删除最大值,把最后一个数字挪到开头,然后下沉
    void pop(){
        heap[0]=heap.back();
        heap.pop_back();//移除
        sink(0);//维持最大堆
    }

    //打印
    void print(){
        for(auto& h:heap){
            printf("%d ",h);
        }
    }

private:
    //上浮
    void swim(int pos){
        while(pos>=1&&heap[pos/2]<heap[pos]){
            swap(heap[pos/2],heap[pos]);
            pos/=2;
        }
    }

    //下沉
    void sink(int pos){
        int N=heap.size();
        while(2*pos<=N){
            int i=2*pos+1;
            if(i<N&&heap[i]<heap[i+1]) //选择子节点较大者
               ++i;
            if(heap[pos]>=heap[i])
               break;
            swap(heap[pos],heap[i]);
            pos=i;
        }
    }
private:
    vector<int> heap;
};

int main(int argc,char* argv[]){
    vector<int> nums={0,1,2,3,4,8,3,9,5};
    MaxHeap heap;
    for(auto& n:nums){
        heap.push(n);
    }
    heap.print();
    cout<<endl;
    cout<<heap.top()<<endl;
    heap.pop();
    heap.print();
    return 0;
}