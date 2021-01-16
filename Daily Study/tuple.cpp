#include <iostream>
#include <tuple>

auto get_student(int id){
    //返回类型被推断为std::tuple<double,char,std::string>
    if(id==0)
       return std::make_tuple(3.8,'A',"zhangsan");
    if(id==1)
       return std::make_tuple(2.9,'C',"lisi");
    if(id==2)
       return std::make_tuple(1.7,'C',"wangwu");
    return std::make_tuple(0.0,'D',"null");
}

int main(int argc,char* argv[]){
    auto student=get_student(1);
    std::cout<<"ID: 1, "
    <<"GPA: "<<std::get<0>(student)<<", "
    <<"成绩: "<<std::get<1>(student)<<", "
    <<"姓名: "<<std::get<2>(student)<<"\n";
    double gpa;
    char grade;
    std::string name;
    //元祖拆包
    std::tie(gpa,grade,name)=get_student(2);
    std::cout<<"ID: 2, "
    <<"GPA: "<<gpa<<", "
    <<"成绩: "<<grade<<", "
    <<"姓名: "<<name<<"\n";
    return 0;
}