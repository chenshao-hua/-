/*手撕实现二叉堆*/
#include <iostream>
#include <vector>
#include <algorithm>//二叉堆的头文件
#include <functional>//实现greater<int>、less<int>

using namespace std;


int main(int argc,char* argv[]){
    vector<int> a;
    a.push_back(5);
    a.push_back(2);
    a.push_back(3);
    a.push_back(6);
    a.push_back(7);
    /*创建堆*/
    printf("make_heap default(bigheap):\n");
    make_heap(a.begin(),a.end());
    for(int i=0;i<a.size();i++){
        printf("a[%d]=%d\n",i,a[i]);
    }
    cout<<endl;
    /*创建最大堆*/
    make_heap(a.begin(),a.end(),greater<int>());
    for(int i=0;i<a.size();i++){
        printf("a[%d]=%d\n",i,a[i]);
    }
    cout<<endl;
    /*创建最小堆*/
    make_heap(a.begin(),a.end(),less<int>());
    for(int i=0;i<a.size();i++){
        printf("a[%d]=%d\n",i,a[i]);
    }

    return 0;
}