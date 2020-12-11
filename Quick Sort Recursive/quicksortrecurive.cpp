/*实现快速递归*/
#include <iostream>

using namespace std;

template<typename T>
class QuickSortRecurive{
private:
    void quick_sort_recurive(T arr[],int start,int end);
public:
    void quicksort(T arr[],int len);
};
template<typename T>
void QuickSortRecurive<T>::quick_sort_recurive(T arr[],int start,int end){
    if(start>=end)
        return;
    T mid=arr[end];
    int left=start,right=end-1;
    /*查找比目标值小或者大的元素,然后左右两侧的元素进行交换*/
    while(left<right){
        /*从左侧查找比目标值更大的元素*/
        while(arr[left]<mid&&left<right)
             left++;
        /*从右侧查找比目标值更大的元素*/
        while(arr[right]>=mid&&left<right)
             right--;
        /*交换元素*/
        swap(arr[left],arr[right]);
    }
    
    if(arr[left]>=arr[end]){
        swap(arr[left],arr[end]);
    }else{
        left++;
    }
    quick_sort_recurive(arr,start,left-1);
    quick_sort_recurive(arr,left+1,end);
}

template<typename T>
void QuickSortRecurive<T>::quicksort(T arr[],int len){
    quick_sort_recurive(arr,0,len-1);
}

int main(int argc,char* argv[]){
    int num[]={3,6,2,9,5,10,4,6};
    auto len=sizeof(num)/sizeof(num[0]);
    QuickSortRecurive<int>().quicksort(num,len);
    for(auto i=0;i<len;i++)
        cout<<num[i]<<" ";
    cout<<endl;
    return 0;
}