/*
策略模式：
定义一组算法，将每个算法封装起来，并且使得它们之间可以进行互换，这样算法能够独立于
使用它的客户端而变化。也就是说这些算法所完成的功能类型是一样的，对外接口也是一样的，
知识不同策略使得环境角色表现出不同的行为。

从图中可以了解到，策略模式涉及到三个角色：
（1）Context(环境角色):持有一个Strategy的引用。用来操作策略的上下文环境，屏蔽高层
模块(客户端)对策略算法的直接访问，封装可能存在的变化。
（2）Strategy(抽象策略角色):通常由一个接口或者抽象类实现。此角色出所有的具体策略类所
需的接口。
（3）ConcreteStrategy(具体策略角色):具体的策略或算法实现。

策略模式关注于类方法实现的多样性，而工厂模式关注于类对象的多样性。

案例：
这里用一个出行方式的例子来说明策略模式，假如小张要出差某个地方，路线是从深圳到达这
个地方，那么有三种出行方式可以选择：飞机、火车、汽车，本例子将这三种出行方式(ConcreteStrategy)
抽象出来作为实际策略对象，一张票单(context)可以选择任意一种方式出行，这就是一种
简单的策略模式。
*/

#include <iostream>
#include <string>

using namespace std;

/*抽象策略*/
class AbstractTravel{
public:
    virtual void travelticket(const string& str)=0;
};


/*ConcreteStrategy(算法实例)*/
class PassengerTicket:public AbstractTravel{
public:
    void travelticket(const string& str){
        printf("到达%s预计需要4个小时",str.c_str());
    }
};

class BusTicket:public AbstractTravel{
public:
    void travelticket(const string& str){
        printf("到达%s预计需要23个小时",str.c_str());
    }
};

class RailwayTicket:public AbstractTravel{
public:
    void travelticket(const string& str){
        printf("达到%s预计需要11个小时",str.c_str());
    }
};

/*上下文Context*/
class Ticket{
public:
    Ticket():travel(nullptr){address.clear();}
    void selectaddress(const string& _address){
        address=_address;
    }
    void selecttravel(AbstractTravel* _travel){
        travel=_travel;
    }
    void order(){
        if(address.size()>0)
          travel->travelticket(address);
        else
          cout<<"请选择目的地！"<<endl;
    }

private:
    AbstractTravel* travel;
    string address;
};


enum traveltype{
    Airplane,
    Bus,
    Railway
};
/*客户端(Client)*/
int main(int argc,char* argv[]){
    Ticket ticket;
    AbstractTravel*  travelway;
    traveltype type=Bus;
    switch(type){
        case Airplane:
            travelway=new PassengerTicket;
            break;
        case Bus:
            travelway=new BusTicket;
            break;
        default:
            travelway=new RailwayTicket;
            break;
    }
    ticket.selecttravel(travelway);
    ticket.selectaddress("北京");
    ticket.order();
    delete travelway;
    return 0;
}