/*学生信息管理系统*/
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

class Student{

public:
    string name;/*char name[20]名字*/
    char sex[4];/*性别*/
    int number;/*学号*/
    int score[3];/*分数*/
    int total;/*总分*/
    float average;/*平均分*/

public:
    Student(){};
    Student& operator=(Student& s);
    friend istream& operator>>(istream& scin,Student& s);
    friend ostream& operator<<(ostream& scout,Student& s);
};
Student& Student::operator=(Student& s){
    name=s.name;
    strncpy(sex,s.sex,sizeof(s.sex));
    number=s.number;
    for(int i=0;i<sizeof(score)/sizeof(score[0]);++i){
        score[i]=s.score[i];
    }
    total=s.total;
    average=s.average;
    return *this;
}

istream& operator>>(istream& scin,Student& s){
    cout<<"\t学号:";scin>>s.number;
    cout<<"\t姓名:";scin>>s.name;
    cout<<"\t性别:";scin>>s.sex;
    cout<<"\t语文:";scin>>s.score[0];
    cout<<"\t数学:";scin>>s.score[1];
    cout<<"\t英语:";scin>>s.score[2];
    s.total=s.score[0]+s.score[1]+s.score[2];
    s.average=s.total/3;
    return scin;
}

ostream& operator<<(ostream& scout,Student& s){
    scout<<setw(8)<<s.number<<setw(10)<<s.name<<setw(8)<<s.sex<<setw(8)<<s.score[0]
    <<setw(8)<<s.score[1]<<setw(8)<<s.score[2]<<setw(8)<<s.total<<setw(8)<<s.average<<endl;
    return scout;
}

class ManagementSystem{
private:
    vector<Student> stu;
    static int n;
public:
    ManagementSystem():stu(100){}
    void add();      /*添加学生信息*/
    void printinfo();/*查看学整个学生信息*/
    void find();     /*查找学生的信息*/
    void modify();   /*修改学生信息*/
    void deleted();  /*删除学生信息*/
    void sort();     /*学生排序*/
    void save();     /*保存学生信息并写入文件*/
    void read();     /*打开学生信息文件*/
};
int ManagementSystem::n=0;

void ManagementSystem::add(){
    char flag='Y';
    while(flag!='N'||flag!='n'){
        if(flag=='Y'||flag=='y'){
            cin>>stu[n];
            cout<<"添加成功!"<<endl;
            n++;
        }else{
            cout<<"请重新输入..."<<endl;
        }
        cout<<"添加学生? Y/N"<<endl;
    }
}

void ManagementSystem::printinfo(){
    if(n){
        cout<<"-------------------------------------------------------"<<endl;
        cout<<setw(8)<<"学号"<<setw(10)<<"姓名"<<setw(8)<<"性别"<<setw(8)<<"语文"
    <<setw(8)<<"数学"<<setw(8)<<"英语"<<setw(8)<<"总分"<<setw(8)<<"平均分"<<endl;
        for(int i=0;i<n;++i)
           cout<<stu[i];
    }
    getchar();
}

void ManagementSystem::find(){
    
}
int main(int argc,char* argv[]){
    ManagementSystem stu;

    return 0;
}