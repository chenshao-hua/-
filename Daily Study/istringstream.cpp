#include <iostream>
#include <sstream>

using std::cout;
using std::endl;

int main(int argc,char* argv[]){
#if 0
    char a,b,c;
    std::istringstream is("  123");
    is>>std::skipws>>a>>b>>c;
    std::cout<<a<<b<<c<<std::endl;

    is.seekg(0);/*让文件指针定位到文件开头,省略了ios::beg*/
    is>>std::noskipws>>a>>b>>c;
    std::cout<<a<<b<<c<<std::endl;
#endif
    
    char a[10]="hello";
    int c[5]={10,12};
    std::cout<<c<<std::endl;
    std::cout<<a<<" "<<a[0]<<std::endl;
    const char *b="hello";
    std::cout<<b<<std::endl;/*cout在遇到字符型指针时会将其当作字符串名来处理*/
    cout<<static_cast<const void*>(b)<<endl;
    //printf("%s:%p\n",b,b);
    return 0;
}