/*lock_guard()是一个类模板，里面已经存在lock()和unlock()
函数，因此只需要一个即可*/

#include <iostream>
#include <thread>
#include <mutex>
#include <deque>

class lock_guard{
public:
    void WriteOperate(){
        for(auto i=0;i<1000;i+=2){
            std::lock_guard<std::mutex> nums_lockguard(nums_mutex);
            nums_deque.push_back(i);
        }
    }
    
    void ReadOpreate(){
        for(auto i=0;i<1000;i++){
            std::lock_guard<std::mutex> nums_lockguard(nums_mutex);
            if(!nums_deque.empty()){
                std::cout<<nums_deque.front()<<std::endl;
                nums_deque.pop_front();
            }
        }
    }
private:
    std::deque<int> nums_deque;
    std::mutex nums_mutex;
};

int main(int argc,char*[]){
    lock_guard guard;
    std::thread nums_thread1(&lock_guard::WriteOperate,std::ref(guard));
    std::thread nums_thread2(&lock_guard::ReadOpreate,std::ref(guard));
    
    /*线程阻塞*/ 
    nums_thread1.join();
    nums_thread2.join();
    std::cout<<"执行完毕!"<<std::endl;
    return 0;
}