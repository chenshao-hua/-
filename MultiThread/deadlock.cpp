/*
死锁:
通俗解释：
小明：在广州办公，等小花电话联系，不主动拨打电话；
小花：在深圳办公，等小明电话联系，不主动拨打电话；
比如：两把锁a、b，线程A拿到了a锁，线程B拿到了b锁，然后线程A又想去拿b锁，线程B
又想去拿a锁，而且它们没有释放已有的锁。
*/

#include <iostream>
#include <thread>
#include <string>
#include <vector>
#include <list>
#include <mutex>

using namespace std;

class deadLock{
public:
    /*此线程将消息写入到队列中*/
    void WriteMessage(){
        for(int i=0;i<100;i++){
            cout<<"WriteMessage()执行，增加一个元素"<<i<<endl;
            mutex1.lock();
            mutex2.lock();
            message.push_back(i);
            mutex2.unlock();
            mutex1.unlock();
        }
    }
    void ReadMessage(){
        bool flag=false;
        for(int i=0;i<100;i++){
            mutex2.lock();
            mutex1.lock();
            if(!message.empty()){
                message.pop_front();
                mutex2.unlock();
                mutex1.unlock();
                flag=true;
            }
            mutex2.unlock();
            mutex1.unlock();
            if(flag==true){
                cout<<"ReadMessage()执行，取出一个元素"<<endl;
            }else{
                cout<<"WriteMessage()执行，但目前消息队列为空"<<endl;
            }
        }
    }

private:
    list<int> message;/*消息队列，代表玩家发送过来的命令*/
    mutex mutex1,mutex2;/*创建两个互斥量(两把锁)*/
};

int main(int argc,char* argv[]){
    deadLock Lock;
    thread Write(&deadLock::WriteMessage,&Lock);
    thread Read(&deadLock::ReadMessage,&Lock);

    Write.join();
    Read.join();
    return 0;
}