/*华为手机mate40，你即可以使用UBS接口连接电脑来充电，假如只有mate40没有电脑，
怎么办呢？华为提供了mate40电源适配器。可以使用这个电源适配器充电。这个mate40的
电源适配器就是类似我们说的适配器模式。（电源适配器就是把电源变成需要的电压，也就
是适配器的作用是使得一个东西适合另外一个东西。）
在设计模式中，也存在这样一种类似的模式，存在两个接口不同的类，可以使用一个适配器
类来将一个接口转换为客户希望的另外一个接口，称为适配器模式。
*/

#include <iostream>
#include <string>

using namespace std;

class AdministrationSystem_A{
public:
    virtual void GetEmployeeInfo_A(){
        cout<<"甲方公司员工的信息"<<endl;
    }
};

class AdministrationSystem_B{
public:
    virtual void GetEmployeeInfo_B(){
        cout<<"乙方公司员工的信息"<<endl;
    }
};

/*适配器*/
class AdapterSystem:public AdministrationSystem_A{
public:
    //AdapterSystem(AdministrationSystem_B* _System_B):System_B(_System_B){}
    AdapterSystem():System_B(new AdministrationSystem_B){}
    virtual void GetEmployeeInfo_A(){
        System_B->GetEmployeeInfo_B();        
    }
    ~AdapterSystem(){delete System_B;}
private:
    AdministrationSystem_B* System_B;
};

int main(int argc,char* argv[]){
    //AdministrationSystem_B*  B=new AdministrationSystem_B;
    //AdministrationSystem_A*  A=new AdapterSystem(B);
    AdministrationSystem_A*  A=new AdapterSystem;
    A->GetEmployeeInfo_A();
    
    delete A;
    return 0;
}