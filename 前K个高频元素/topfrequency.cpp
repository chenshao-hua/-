
/*哈希表+桶排序*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
static int x=[](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();  //加快输入输出操作

class Solution{
 public:
    
    vector<int> TopFrequency(vector<int>& nums,int k){
        
        unordered_map<int,int> map;
        for(auto& i:nums)  //&引用数组本身，不需要拷贝
           ++map[i];//i代表数组元素，map[i]是元素的个数，进行加1操作
        
        for(auto& j:map)
            bucket.push_back(j.first); //关键字存入桶中
        
        /*
        这样表达也可以
        for(auto j=map.begin();j!=map.end();j++)
            bucket.push_back(j->first);   
        */      
        //sort(begin,end,compare)，三个参数，compare是bool型
        sort(bucket.begin(),bucket.end(),[&map](int a,int b){return map[a]>map[b];});//按照降序排序 
        return vector<int>(bucket.begin(),bucket.begin()+k);//输出前k个高频数组
    }

private:
     vector<int> bucket;

};

int main(int argc,char* argv[]){
    int test[]={1,3,4,4,5,6,9,3,3};
    vector<int> nums(test,test+9);
    for(auto &member:Solution().TopFrequency(nums,2))
         cout<<member<<"  ";
    cout<<endl;
    return 0;
}