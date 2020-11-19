/*lock()和unlock()函数必须同时成对存在，不存在一多一少的情况
lock()调用线程将锁住该互斥量；
(1)若该互斥量当前没有被锁住，则进行加锁；
(2)若当前互斥量被其他线程锁住，则当前的调用线程被阻塞；
(3)若当前互斥量被当前调用的线程锁住，则会产生死锁，因为同一个线程不允许锁两次；
unlock()进行解锁操作，释放互斥量的所有权；
*/

#include <iostream>
#include <thread>
#include <mutex>
#include <deque>

class lock_unlock{
public:
    lock_unlock(){}
    void WriteOperate(){
        for(int i=0;i<1000;i++){
            nums_mutex.lock();
            std::cout<<"写入一个元素"<<std::endl;
            nums_deque.push_back(i);
            nums_mutex.unlock();
        }
    }

    void ReadOperate(){
        for(int i=0;i<1000;i++){
            nums_mutex.lock();
            if(!nums_deque.empty()){
                std::cout<<"读出第一个元素"<<nums_deque.front()<<std::endl;
                nums_deque.pop_front();  
            }
            nums_mutex.unlock();
        }
    }
private:
    std::deque<int> nums_deque;
    std::mutex nums_mutex;
};

int main(int argc,char* argv[]){
    lock_unlock lock;
    std::thread nums_thread1(&lock_unlock::WriteOperate,std::ref(lock));
    std::thread nums_thread2(&lock_unlock::ReadOperate,std::ref(lock));

    /*线程阻塞*/
    nums_thread1.join();
    nums_thread2.join();
    std::cout<<"执行完毕!"<<std::endl;
    return 0;
}