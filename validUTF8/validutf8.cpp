/*
判断数组是否为有效的utf-8.
可以使用bitset类,可以看成是unsigned int型,转换为0或1,它的第0位是最右边的位.
*/

#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

class Solution{
public:
    bool validutf8(vector<int>& data){
        if(data.empty()){
            return false;
        }
        int count=0;
        for(auto& d:data){
            if(d>=248){
                return false;
            }
            bitset<8> num(d);/*转换成二进制,整数越界只取后面8位*/
            cout<<num<<endl;
            if(count==0){
                for(int i=7;i>=0;i--){
                    if(num[i]==0)
                       break;
                    count++;
                }               
                if(count==1||count>4){
                    return false;
                }
                if(count==0){
                    continue;
                }
            }else{
                if(!(num[7]==1&&num[6]==0))
                    return false;
            }
            count--;
        }
        return count==0;
    }
};
int main(int argc,char** argv){
    vector<int> data={235,140,138};
    cout<<Solution().validutf8(data)<<endl;
    return 0;
}