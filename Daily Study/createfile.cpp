#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <cassert>

using namespace std;

int main(int argc,char* argv[]){

#if 0
    ofstream file;
    file.open("count.txt",ios::out|ios::trunc);/*trunc如果文件存在则删除*/
    if(file.is_open()){
        file<<"Let's begin to write"<<endl;
        file<<"This is a line"<<"\n"<<"This is a new line"<<endl;
        file.close();
    }  
#endif

#if 0
    ifstream file;
    file.open("count.txt",ios::in);
    if(!file.is_open()){
        cout<<"Error open file"<<endl;
        exit(1);
    }
    char buf[256];
    string str;
    while(!file.eof()){/*文件末尾*/
        //file.getline(buf,100);
       // file.get(buf,4,'\0');
        //cout<<buf;
        file>>str;
        cout<<str<<endl;
        //cout<<buf<<endl;
    }
    //cout<<buf<<endl;

   ofstream file;
   file.open("count.txt",ios::out|ios::trunc);
   if(!file.is_open()){
       cerr<<"open file erro."<<endl;
       exit(1);
   }
   string name;
   int age;
   while(cin>>name>>age){
       file<<setw(8)<<name<<setw(8)<<age<<endl;//
   }
   file.close();
#endif
   ifstream file("count1.txt",ios::in);
   assert(file);
   file.close();
   return 0;
}