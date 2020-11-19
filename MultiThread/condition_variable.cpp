/*
condition_variable(条件变量)，通俗的将线程根据条件去拿锁，若不符合条件则
休眠，直到有线程唤醒它才会继续去竞争锁，用于线程同步，只能配合unique_lock使用，
前面3个wait函数需要传入一个已经上锁的变量unique_lock<mutex>，此外第二个参数
传入lambda表达式用于防止虚假唤醒;而condition_variable_any可以应用于任意的lock；

(1)wait：阻塞自己，等待唤醒；wait函数存在两个参数，第一个是unique_lock，第二个参数
是lambda表达式或其他函数，返回值是bool，若第二个参数不传入，默认条件判断为false，
相当于互斥锁，即每次都需要notify唤醒，如果所有唤醒线程结束运行，而没有线程唤醒它则
休眠堵塞；
(2)wait_for：阻塞自己，等待唤醒，最多等待一段时间；
(3)wait_unti：阻塞自己，等待唤醒，最多等待到某个时刻；
(4)notify_one：唤醒一个等待在这个条件变量上的线程，若线程没有进入休眠状态则无效；
(5)notify_all：唤醒所有等待在这个条件变量上的线程；
*/

#include <iostream>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <list>

class condition_variables{
public:
    void WriteOperate(){
        for(auto i=0;i<100;i+=2){
            std::unique_lock<std::mutex> mg_lock(mg_mutex);
            message.push_back(i);
            mg_condv.notify_one();/*唤醒线程*/     
        }
    }

    void ReadOperate(){
        for(auto i=0;i<100;i+=2){
            std::unique_lock<std::mutex> mg_lock(mg_mutex);
            /*lambda表达式无参数传入可以省略，this类指针，值传递，返回值bool型，自动匹配类型可省略*/
            mg_condv.wait(mg_lock,[this]{return !message.empty();});
            std::cout<<message.front()<<std::endl;
            message.pop_front();
        }
    }

private:
    std::list<int> message;
    std::mutex mg_mutex;
    std::condition_variable mg_condv;
};

int main(int argc,char* argv[]){
    condition_variables cond;
    std::thread W_thread(&condition_variables::WriteOperate,&cond);
    std::thread R_thread(&condition_variables::ReadOperate,&cond);

    W_thread.join();
    R_thread.join();
    return 0;
}