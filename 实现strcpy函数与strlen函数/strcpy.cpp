#include <iostream>
#include <assert.h>
using namespace std;

char* _strcpy(char* des,const char* src){ 
    assert((des!=NULL)&&(src!=NULL));//断言，如果表达式为假，则报错，并终止退出程序
    char* temp=des;
    while((*des++=*src++)!='\0'); //可以理解为：*des=*src;des++;str++;
    return temp;  //主要是为了实现链式表达，比如：strcpy(a,strcpy(b,c))
}

int _strlen(const char* src){
    if(src==NULL)
       return -1;
    int _length=0;
    while(*src++!='\0')
         _length++;
     return _length;
}
int main(int argc,char* argv[]){
    char* Des;  //指针变量，默认为一个地址
    const char* Src="hello,world";//字符数组，末尾有'\0'
    _strcpy(Des,Src);
    printf("%s\n %d\n",Des,_strlen(Des));
    return 0;
}