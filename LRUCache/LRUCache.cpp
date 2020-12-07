/*
设计和构建一个“最近最少使用”缓存,该缓存会删除最近最少使用的项目.缓存应
该从键映射到值(允许你插入和检索特定键对应的值),并在初始化时指定最大容量.
当缓存被填满时,它应该删除最近最少使用的项目.
它应该支持以下操作:获取数据get和写入数据put.
获取数据get(key)-如果密钥(key)存在于缓存中,则获取密钥的值(总是正数),否则返回 -1。
写入数据put(key,value)-如果密钥不存在,则写入其数据值.当缓存容量达到
上限时,它应该在写入新数据之前删除最近最少使用的数据值,从而为新的数据值
留出空间.

示例:
LRUCache cache = new LRUCache( 2-缓存容量 );

cache.put(1,1);
cache.put(2,2);
cache.get(1);      // 返回  1
cache.put(3,3);    // 该操作会使得密钥 2 作废
cache.get(2);      // 返回 -1 (未找到)
cache.put(4,4);    // 该操作会使得密钥 1 作废
cache.get(1);      // 返回 -1 (未找到)
cache.get(3);      // 返回  3
cache.get(4);      // 返回  4

*/
#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

class Solution{
public:
    Solution(const int& _size):size(_size){}
    /*先通过哈希表检查cache里是否已存在相同key,有则删除,不管有没
    有都要把新key和value对放至头部,如超出容量则再弹出末尾*/
    void put(int key,int value){
        auto index=order.find(key);
        if(index!=order.end()){
            cache.erase(index->second);
            order.erase(key);
        }
        cache.push_front({key,value});
        order.emplace(key,cache.begin());/*emplace插入不重复的元素*/

        if(cache.size()>size){
            order.erase(cache.back().first);
            cache.pop_back();
        }
    }
    /*先找键值表,如有,复制到头部,再删除原有位置元素*/
    int get(int key){
        auto index=order.find(key);
        if(index==order.end())
            return -1;
        auto target=index->second;
        cache.push_front({target->first,target->second});
        cache.erase(target);
        order.erase(key);
        order.emplace(key,cache.begin());
        return cache.front().second;
    }
private:
    const int size;
    list<pair<int,int>> cache;
    unordered_map<int,list<pair<int,int>>::iterator> order;
};

int main(int argc,char* argv[]){
    auto size=2;
    Solution cache(size);
    cache.put(1,3);
    cache.put(2,4);
    cout<<cache.get(1)<<endl;
    cout<<cache.get(2)<<endl;
    cache.put(3,2);
    cout<<cache.get(1)<<endl;
    return 0;
}