#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

class solution{
public:
    solution(string _x):x(_x){}
    void findDNASequence(){
        //初始化map容器的DNA，key是string，对应长度为10的子串
        //value是int类型，对应子串的出现次数
        map<string,int> DNA;
        for(int i=0;i<x.length();++i){//遍历字符串s
            string word=x.substr(i,10);//调用substr函数获取从第i个字符起长度为10的子串
            if(DNA.find(word)!=DNA.end()){//在映射DNA中查找该子串是否存在
                DNA[word]+=1;//如果存在，对应次数加1，起始为0
            }
            else
                DNA[word]=1; //将该子串添加至map中，出现次数赋值为1        
        }
        map<string,int>::iterator it=DNA.begin();
        for(;it!=DNA.end();it++){
            if(it->second>1){
                result.push_back(it->first);//如果遍历到出现次数大于1的子串，将其存储至result中
            }
        }
        //cout<<DNA.size()<<endl;
        //cout<<result.size()<<endl;
    }
    void print(){
        for(int i=0;i<result.size();i++)
                cout<<result[i]<<endl;
    }
private:
    string x;
    vector<string> result; //设置字符串数组的result，存储满足条件的结果
};

int main(int argc,char* argv[]){
    string _x="AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    solution temp(_x);
    temp.findDNASequence();
    temp.print();
    return 0;
}
