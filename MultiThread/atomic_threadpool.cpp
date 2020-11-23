#include <iostream>
#include <atomic>
#include <thread>
#include <vector>

std::atomic<int> count(0);

/*原子操作*/
void sumTask(){
    for(auto i=0;i<1000;i++)
       count++;
}

int main(int argc,char* argv[]){
    std:: vector<std::thread> threadpool;
    for(auto i=0;i<10;i++)
        threadpool.push_back(std::thread(sumTask));

    for(auto i=0;i<10;i++){
        std::cout<<threadpool[i].get_id()<<" ";
        threadpool[i].join(); 
        std::cout<<std::endl;
    }
    std::cout<<count<<std::endl;   
    return 0;
}