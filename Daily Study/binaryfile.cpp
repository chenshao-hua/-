#include <iostream>
#include <fstream>

using namespace std;

class Student{
public:
    char name[20];
    int age;
};

int main(int argc,char* argv[]){
    Student stu;
    /*
    ofstream outfile("studen.dat",ios::out|ios::binary);
    while(cin>>stu.name>>stu.age){
        outfile.write((char*)&stu,sizeof(stu));
    }
    outfile.close();
    */
   ifstream infile("studen.dat",ios::in|ios::binary);
   if(!infile.is_open()){
       cerr<<"error open file"<<endl;
       return 0;
   }
   while(infile.read((char*)&stu,sizeof(stu)))
      cout<<stu.name<<" "<<stu.age<<endl;
    infile.close();
    return 0;
}