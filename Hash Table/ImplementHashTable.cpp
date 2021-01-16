/*
手撕哈希表
最简单的哈希思想,利用数组下标记录元素是否存在.
如果整数比较大时,使用哈希求余数;
字符串同理;
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution{

public:  
    Solution(){}
     void create_hash(vector<int>& a,vector<int>& table){
         int i=0;    
         for(;i<a.size();++i){
             table[a[i]]++;
         }
     }
     int find_key(int key,vector<int>& table){
         return table[key]!=0;
     }

     /*Implement sort*/
     void sort(vector<int>& a,vector<int>& table){
         int k=0;
         for(int i=0;i<table.size();++i){
             for(int j=0;j<table[i];++j){
                 /*table[i]代表元素i出现的次数*/
                 a[k++]=i;/*将table[i]个i添加到数组a中*/
             }
         }
     }
     /*int型或long型*/
     int int_func(int key,vector<int>& table){
         return key%table.size();
     }

     /*string型*/
     int string_func(const char* key,vector<int>& table){
         int sum=0;
         while(*key){
             sum+=*key;
             key++;
         }
         return sum%table.size();
     }
};
int main(int argc,char* argv[]){
    vector<int> a={7,17,5,8,2,9,20,3,2,5};
    /*设置一个长度为100的数组table*/
    vector<int> table(100,0);
    Solution hash;
    hash.create_hash(a,table);
    printf("In hash table:\n");
    for(int i=0;i<table.size();++i){
        if(table[i]>0){
            /*打印i值出现的次数table[i]*/
            printf("%d appear %d times.\n",i,table[i]);
        }
    }

    printf("test:\n");
    for(int i=1;i<=10;++i){
        if(hash.find_key(i,table)){
            printf("%d is in array.\n",i);
        }else{
            printf("%d is not in array.\n",i);
        }
    }

    printf("implement sort:\n");
    hash.sort(a,table);
    for(auto& num:a){
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}