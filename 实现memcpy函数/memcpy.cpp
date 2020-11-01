/*strcpy和memcpy的区别：
复制内容不同；strcpy只能复制字符串，而memcpy可以复制任意内容，比如整型、字符数组、结构体、类等。
复制的方法不同；strcpy不需要指定长度，遇到字符串结束符'\0'便结束，而memcpy则是根据其第3个参数决定复制的长度。
*/


#include <iostream>
#include <assert.h>

void* _memcpy(void* des,const void* src,int size){
   assert((des!=NULL)&&(src!=NULL));
   char* tempdes=(char*)des;
   char* tempsrc=(char*)src;
   while(size--)
       *tempdes++=*tempsrc++; //等价于先size，然后 *tempdes=*tempsrc， tempdes++，*tempsrc
    return tempdes;
}

int main(int argc,char* argv[]){
    char* Des;//如果声明为字符数组，需要注意越界的问题，char Des[20]，最后有个'\0'字符
    const char* Src="Hello,China";
    memcpy(Des,Src,4);
    printf("%s\n",Des);
    return 0;
}
