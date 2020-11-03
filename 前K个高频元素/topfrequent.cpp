
/*哈希表+桶排序*/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
static int x=[](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();  //加快输入输出操作

bool compare(const pair<int,int>& a,const pair<int,int>& b){
        return a.second>b.second;
}

class Solution{
 public:
    vector<int> topfrequent(vector<int>& nums,int k){
        map<int,int> elements;
        for(int i=0;i<nums.size();i++)
            elements[nums[i]]++;//nums代表数组元素，elemets[i]是元素的个数，进行加1操作
        
        for(auto it=elements.begin();it!=elements.end();it++)
            butkets.push_back(pair<int,int>(it->first,it->second));

        sort(butkets.begin(),butkets.end(),compare);//按照降序排序,自定义compare，传入pair

        vector<int> result;//用于存储结果
        for(int i=0;i<k;i++)
             result.push_back(butkets[i].first);

        return result; 

    }
    
private:
     vector<pair<int,int>> butkets;//关键字存入桶中，第一个值为元素，第二个值为元素数量

};

int main(int argc,char* argv[]){
    int test[]={1,3,4,4,5,6,9,3,3};
    vector<int> nums(test,test+9);
    for(auto &member:Solution().topfrequent(nums,2))
         cout<<member<<"  ";
    cout<<endl;
    return 0;
}