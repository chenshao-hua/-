/*二叉最大堆的实现*/
#include <iostream>
#include <vector>

using namespace std;

class greaterheap{
public:
    void make_heap(vector<int>& a){
        for(int i=a.size()-1;i>=0;i--){
            heap_down(a,i);/*从后向前调用heap_down调整a的每个元素*/
        }
    }
private:
    /*传入数组a和下标i,i的左右子树都满最大堆的性质,函数将a整体调整为最大值*/
    void heap_down(vector<int>& a,int i){
        while(i<a.size()){
            int left=2*i+1,right=2*i+2,maxium=i;;/*i的左子节点下标和右子节点下标,并设置maxium存储i
            和左右子节点较大节点的下标,初始化i*/
            if(left<a.size()&&a[maxium]<a[left]){
                maxium=left;/*左子树存在且a[maxium]小于a[left],则更新maxium为left*/
            }
            if(right<a.size()&&a[maxium]<a[right]){
                maxium=right;/*右子树存在且a[maxium]小于a[right],则更新maxium为right*/
            }
            if(maxium==i) break;/*此时maxium仍然等于i则说明a[i]比左右子树节点都大,满足条件,跳出循环*/

            /*交换a[i]和a[maxium]或用swap*/
            int temp=a[i];
            a[i]=a[maxium];
            a[maxium]=temp;
            i=maxium;/*将i指向maxium,继续向下调整*/
        }
    }
};

int main(int argc,char* argv[]){
    vector<int> a={1,2,3,4,5,6,7,8,9,10};
    greaterheap().make_heap(a);
    printf("make_heap:\n");
    for(int i=0;i<a.size();i++){
        printf("[%d]",a[i]);
    }
    printf("\n");
    return 0;
}