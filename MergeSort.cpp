#include <iostream>
#include <vector>
using namespace std;

/*时间复杂度：o(nlogn)*/
class Solution{
public:
     Solution(vector<int>& x):array(x),leftarray(new int[x.size()/2]){}
     ~Solution(){delete [] leftarray;}
     void mgsort(){
         Sort(0,array.size());
         for(auto x:array)
              cout<<x<<" ";
        cout<<endl; 
     }

private:
     int* leftarray; //左边数组
     vector<int> array;

    /*将[begin,end)和[mid,end)范围的序列合并成一个有序序列*/
     void Mergesort(int begin,int mid,int end){

         int li=0,le=mid-begin; //左边数组lefrarray,li代表索引，le代表长度
         int ri=mid,re=end;     //右边数组,ri代表索引，re代表末尾
         int ai=begin;    //整个数组array，索引位置
        
        //备份左边数组
        for(int i=li;i<le;i++)
            leftarray[i]=array[begin+i];
        
        //如果左边还没结束
        while(li<le){
            if(ri<re&&array[ri]<leftarray[li])  //满足条件，右边数组赋值
                array[ai++]=array[ri++];  //在已有的数组里面更改，等价于：array[ai]=array[ri],ai++,ri++
            else
                array[ai++]=leftarray[li++];     //新建的左边数组赋值       
        } 
     }
     /*对[begin,end)范围的数据进行归并排序*/
     void Sort(int begin,int end){
         if(end-begin<2)  //一个数或者没有返回
            return;
         int mid=(end+begin)>>1;//取中间的位置
         
         Sort(begin,mid);      //时间复杂度：T(n)=T(n/2)+T(n/2)+O(n)
         Sort(mid,end);//左闭右开
         //cout<<begin<<" "<<mid<<"  "<<end<<"  "<<endl;
         Mergesort(begin,mid,end);
     } 

};
int main(int argc,char* argv[]){
    vector<int> array{8,5,7,6,1,9,2,3};
    Solution temp(array);
    temp.mgsort();
    return 0;
}