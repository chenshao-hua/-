/*
工厂模式:简单工厂模式、工厂方法模式、抽象工厂模式

工厂模式的主要作用是封装对象的创建，分离对象的创建和操作过程，用于批量管理对象
的创建过程，便于程序的维护和扩展。

*/
/*
#include <iostream>
#include <memory> //智能指针
using namespace std;

//简单工厂模式
typedef enum PhoneTypeTag{
    XiaoMi_Phone,
    IPhone_Phone,
    HuaWei_Phone
}PhoneType;

//手机抽象类
class Phone{
public:
    virtual void phonetype()=0;
};

//具体产品
class XiaoMiPhone:public Phone{
public:
    void phonetype() override{//override为保留字,表示重写了基类的虚函数,可以避免忘记重写
        cout<<"I'm XiaoMi Phone!"<<endl;
    }
};

class IPhone:public Phone{
public:
    void phonetype() override{
        cout<<"I'm IPhone!"<<endl;
    }
};

class HuaWeiPhone:public Phone{
public:
    void phonetype() override{
        cout<<"I'm HuaWei Phone!"<<endl;
    }
};

//工厂类-手机代工厂
class PhoneFactory{
public:
    //根据产品信息创建具体的产品类示例,返回一个抽象产品类
    shared_ptr<Phone> MakePhone(const PhoneType Type){
        switch(Type){
            case PhoneType::XiaoMi_Phone:
                 return make_shared<XiaoMiPhone>();
            case PhoneType::IPhone_Phone:
                 return make_shared<IPhone>();
            case PhoneType::HuaWei_Phone:
                 return make_shared<HuaWeiPhone>();
            default:
                 return nullptr;
        }
    }
};

int main(int argc,char* argv[]){
    PhoneFactory phoneFactory;
    shared_ptr<Phone> m_phone;

    m_phone=phoneFactory.MakePhone(PhoneType::XiaoMi_Phone);
    m_phone->phonetype();

    m_phone=phoneFactory.MakePhone(PhoneType::IPhone_Phone);
    m_phone->phonetype();

    m_phone=phoneFactory.MakePhone(PhoneType::HuaWei_Phone);
    m_phone->phonetype();

    return 0;
}
*/
/*
1.工厂类含有必要的判断逻辑,可以决定在什么时候创建哪一个产品类的实例,客户端
可以免除直接创建产品对象的责任,而仅仅“消费”产品;简单工厂模式通过这种做法
实现了对责任的分割,它提供了专门的工厂类用于创建对象.
2.客户端无须直到所创建的具体产品类的类名,只需知道具体产品类所对应的参数即可,
对于一些复杂的类名,通过简单工厂模式可以减少使用者的记忆量.
工厂模式的最大优点就是屏蔽产品的具体实现,调用者只需关心产品的接口.当然,它也有
自己的问题,产品种类可能有成千上万,如果都是依靠同一个工厂生产,那么必然会使得
工厂代码极其庞大,这就有了工厂方法的设计实现.
*/

/*其实这才是正宗的工厂模式,简单工厂模式只是一个简单的对创建过程的封装.
在代码实现上,工厂方法模式在简单工厂模式的基础上增加对工厂的基类抽象,
不同的产品创建采用不同的工厂创建(从工厂的抽象基类派生),这样创建不同的产品
过程就由不同的工厂分工解决:FactoryA专门负责生产ProductA,FactoryB专门
负责生产ProductB,FactoryA和FactoryB之间没有关系;如果到了后期,如果
需要生产ProductC时,我们则可以创建一个FactoryC工厂类,该类专心负责生产
ProductC类产品.
该模式相对于简单工厂模式的优势在于:便于后期产品种类的扩展.如果需要增加
新的产品类,只需要扩展一个相应的工厂类即可.
*/


#include <iostream>
#include <memory>

using namespace std;

//工厂方法模式

//产品抽象类

class Phone{
public:
    Phone(){}
    virtual void type()=0;
};

//具体的产品类

class XiaoMiPhone:public Phone{
public:
    XiaoMiPhone(){}
    void type() override{
        cout<<"I'm XiaoMi Phone."<<endl;
    }
};

class IPhone:public Phone{
public:
    void type() override{
        cout<<"I'm IPhone."<<endl;
    }
};

class HuaWeiPhone:public Phone{
public:
    void type() override{
        cout<<"I'm HuaWei Phone."<<endl;
    }
};

//抽象工厂类,提供一个创建接口
class PhoneFactory{
public:
    virtual shared_ptr<Phone> MakePhone()=0;
};

//具体创建工厂类,使用抽象工厂类提供的接口,各具体的工厂去创建具体的产品
class XiaoMiPhoneFactory:public PhoneFactory{
public:
    shared_ptr<Phone> MakePhone() override{
        return make_shared<XiaoMiPhone>();
    }
};

class IPhoneFactory:public PhoneFactory{
public:
    shared_ptr<Phone> MakePhone() override{
        return make_shared<IPhone>();
    }
};

class HuaWeiPhoneFactory:public PhoneFactory{
public:
    shared_ptr<Phone> MakePhone() override{
        return make_shared<HuaWeiPhone>();
    }
};
int main(int argc,char* argv[]){

    shared_ptr<Phone> phone;
     //生产小米
    phone=XiaoMiPhoneFactory().MakePhone();
    phone->type();
    //生产苹果
    phone=IPhoneFactory().MakePhone();
    phone->type();
    //生产华为
    phone=HuaWeiPhoneFactory().MakePhone();
    phone->type();
    return 0;
}
