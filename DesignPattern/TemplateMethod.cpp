/*
模板方法模式
概念：
在一个方法中定义一个算法的骨架，然后将一些具体实现步骤延迟到子类中。模板方法使得子类可以不改变算法
结构的情况下，重新定义算法中的某些步骤的实现。模板方法可以为程序员提供一种代码复用的重要技巧。因为
模板方法的抽象类可以定义具体方法、抽象方法，并且该抽象方法由子类去实现。
抽象类(AbstractClass):定义抽象的原语操作,具体的子类将重定义它们以实现一个算法,实现一个模板方法,定义一个算法的骨架。该模板方法不仅调用原语操作，也调用定义
具体子类(ConcreteClass):实现原语操作以完成算法中与特定子类相关的步骤。
*/

/*
假如你是一位中国银行的柜员，他可以办理注册账户的业务。对于来自全国不同地方的客户，你会如何制作一份用户信息表格，可以
应对信息差异的客户呢？需要明确的是，用户信息表格需要填写用户的姓名、住址、身份证号、手机号这四样重要信息，毋庸置疑，
这份用户信息表格只需要一份模板，唯一存在差异的地方是，这四个信息的具体实现方法不同。因此，只需要设计好这样的用户信息表格，
然后发给前来办理业务的客户即可，不需要客户每个人都重新写一份这样的表格。
模板方法模式正是基于这样的原理，把用户信息表格抽象成基类（父类），并留下客户填写姓名、住址、身份证号、手机号的空白位置。
*/
#include <iostream>
using namespace std;
class ClientInfo{
public:
    void ClientInformation(){
        ClientName();
        ClientAddr();
        ClientId();
        ClientNum();
    }
private:
    void ClientAddr(){
        cout<<"地  址：";
        Information1();
    }
    void ClientId(){
        cout<<"身份证号：";
        Information2();
    }
    void ClientNum(){
        cout<<"手 机 号：";
        Information3();
    }
protected:
    virtual void ClientName()=0;
    virtual void Information1()=0;
    virtual void Information2()=0;
    virtual void Information3()=0;
};

/*
从上面的 ClientName()，Information1()，Information2()，Information3()，就是客户办理业务填写
信息的地方，因此客户不需要拿一张白纸重新填写“姓名”，“地址”，“身份证号”，“手机号”这些信息，只需要按照
指定格式完成即可。模板方法就需要实现这四个方法。
*/

/*张三的用户信息表*/
class ZhangSanInfo:public  ClientInfo{
public:
    void ClientName(){
        cout<<"姓  名：张三"<<endl;
    }
    void Information1(){
        cout<<"北京市东城区"<<endl;
    }
    void Information2(){
        cout<<"440883199712235874"<<endl;
    }
    void Information3(){
        cout<<"17612467890"<<endl;
    }
};

/*李四的用户信息表*/
class LiSiInfo:public  ClientInfo{
public:
    void ClientName(){
        cout<<"姓  名：李四"<<endl;
    }
    void Information1(){
        cout<<"上海市浦东新区"<<endl;
    }
    void Information2(){
        cout<<"441884199801234971"<<endl;
    }
    void Information3(){
        cout<<"17923890143"<<endl;
    }
};

/*客户端*/
int main(int argc,char* argv[]){
    ClientInfo* Info1=new ZhangSanInfo;
    Info1->ClientInformation();
    LiSiInfo Info2;
    Info2.ClientInformation();
    delete Info1;
    return 0;
}

/*
适用场景：
（1）多个子类有共有的方法，并且逻辑基本相同；
（2）重要、复杂的算法，可以把核心算法设计为模板方法，周边的相关细节功能则由各个子类实现；
（3）重构时，模板方法是一个经常使用的方法，把相同的代码抽取到父类中，然后通过构造函数约束其行为；

优点：
（1）模板方法模式是通过把不变的行为挪到一个统一的父类，从而达到去除子类中重复代码的目的；
（2）子类实现模板父类的某些细节，有助于模板父类的扩展；
（3）通过一个父类调用子类实现的操作，通过子类扩展增加新的行为，符合“开放-封闭原则”；

缺点：
按照设计习惯，抽象类负责声明最抽象、最一般的事物属性和方法，实现类负责完成具体的事务
属性和方法，但是模板方式正好相反，子类执行的结果影响了父类的结果，会增加代码阅读的难度。
此外每个不同的实现都需要定义一个子类，这会导致类的个数增加，系统更加庞大。
*/