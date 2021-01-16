/*
尝试使用栈(stack)来实现队列(queue).

Example:
MyQueue queue=new MyQueue();
queue.push(1);
queue.push(2);
queue.peek();//returns 1
queue.pop();//returns 1
queue.empty();//return false

解题思路:
可以使用两个栈来实现一个队列:根据队列先进先出的思想,所以必须有一个额外栈翻转一次数组.这个翻转的数组可以在插入时完成,
也可以在取值的时候完成.
*/
#include <iostream>
#include <stack>

using namespace std;
class MyQueue{
private:
    stack<int> in,out;
    /*翻转数组*/
    void in2out(){
        if(out.empty()){
            while(!in.empty()){
                int x=in.top();
                in.pop();
                out.push(x);
            }
        }
    }
public:
    MyQueue(){}
    /*入队*/
    void push(int x){
        in.push(x);
    }
    /*出队*/
    int pop(){
        in2out();
        int x=out.top();
        out.pop();
        return x;
    }
    /*队首*/
    int peek(){
        in2out();
        return out.top();
    }
    /*队尾*/
    int back(){
        return in.top();
    }
};

int main(int argc,char* argv[]){
    MyQueue queue;
    queue.push(4);
    queue.push(1);
    cout<<queue.peek()<<endl;
    return 0;
}