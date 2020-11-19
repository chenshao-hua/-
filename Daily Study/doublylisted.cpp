#include <iostream>
#include <vector>
#include <memory>
using namespace std;
class Demo{
private:
    int m_c;
public:
    Demo(int c):m_c(c){} 
};

class DemoA{
private:
    int m_a;
    //vector<unique_ptr<int>> temp;
    //vector<shared_ptr<Demo>> temp;
    //vector<unique_ptr<Demo>> temp;
public:
    void show();
    DemoA(int val);
    DemoA(const DemoA& e):m_a(e.m_a){}
    ~DemoA(){
#if 0
        vector<Demo*>::iterator it=temp.begin();
        for(;it!=temp.end();++it){
            delete *it;
            *it=NULL;
        }
#endif
    }
};
DemoA::DemoA(int val){
    this->m_a=val;
    //temp.push_back(make_shared<Demo>(11));
    //temp.emplace_back(new Demo(10));
    //temp.emplace_back(make_unique<Demo>(10));
}
void DemoA::show(){
    //cout<<temp.size()<<endl;
    cout<<"DemoA:"<<m_a<<endl;
}

class DemoB:public DemoA{
private:
    int m_b;
public:
    void show();
    DemoB(int aval,int bval);
    DemoB(const DemoB& d):DemoA(d),m_b(d.m_b){}
    DemoB& operator=(DemoB&);
};

DemoB::DemoB(int aval,int bval):DemoA(aval){
    m_b=bval;
}
void DemoB::show(){
    DemoA::show();
    //cout<<DemoA::m_a<<endl;
    cout<<"DemoB:"<<m_b<<endl;
}

DemoB& DemoB::operator=(DemoB& b){
    DemoA::operator=(b);
    m_b=b.m_b;
    return *this;
}


int main(int argc,char* argv[]){
    //vector<unique_ptr<Demo>> temp;
    DemoA a(10);
    DemoB b(11,12);
    a.show();
    b.show();
    a=b;
    a.show();
    return 0;
}

