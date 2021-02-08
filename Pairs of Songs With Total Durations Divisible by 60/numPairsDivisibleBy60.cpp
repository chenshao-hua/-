/*
You are given a list of songs where the ith song has a duration of time[i] seconds.
Return the number of pairs of songs for which their total duration in seconds is divisible
by 60.Formally,we want the number of indices i,j such that i<j with (time[i]+time[j]%60==0).

Example 1:
Input:time=[30,20,150,100,40]
Output:3
Explanation:Three pairs have a total divisible by 60:
(time[0]=30,time[2]=150):total duration 180
(time[1]=20,time[3]=100):total duration 120
(time[1]=20,time[4]=40) :total duration 60

Example 2:
Input:time=[60,60,60]
Output:3
Explanation:All three pairs hava a total duration of 120,which is divisible by 60.

题目大意:
给出一个歌曲列表的每首歌播放时长,找出有多少对的歌曲,使得其播放时长之和是60的倍数.这个对按照数组的顺序.

解题思路:
方法1:
双层枚举,超时.
方法2:
先对60取余存储在map数组中,key为余数,其value值存储的是余数对应的个数,然后双指针进行遍历.需要注意当余数为0或者
退出循环中间值为30的时候时,整除60的个数为其:n(n-1)/2,此外当满足l+r=60,其个数进行相乘即可.
方法3:
题目给的ti的范围是:0<t<=500;
利用对60取余数的算法,这样就可以把数字缩小到[0,59]的范围内,对于每次遍历到的数字,加上能和其配对的数字的出现
的次数,方法是利用600减去当前数字,然后对60取余.然后累加对60取余的次数.
*/
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution{
public:
    int numPairDivisibleBy60(vector<int>& time){
        int count=0;
        /*
        for(int i=0;i<time.size()-1;i++){
            for(int j=i+1;j<time.size();j++){
                if((time[i]+time[j])%60==0){
                    cout<<i<<" "<<j<<endl;
                    count++;
                }
            }
        }
        */
       vector<int> res(60);
       for(const auto& t:time){
           count+=res[(600-t)%60];
           ++res[t%60];
       }
        return count;
    }
    int numPairsDivisibleBy601(vector<int>& time){
        int res=0;
        map<int,int> board;
        for(auto& t:time){
            board[t%60]++;     
        }
        for(auto b:board){
            cout<<b.first<<" "<<b.second<<endl;
        }
        auto L=board.begin();
        auto R=board.end();
        R--;
        if(L->first==0){
            res=(L->second-1)*(L->second)>>1;
        }
        while(L->first<R->first){
            if(L->first+R->first==60){
                res+=(L->second)*(R->second);
                cout<<res<<endl;
                L++,R--;
            }else if(L->first+R->first<60){
                L++;
            }else{
                R--;
            }
        }
        if(L->first==30){
            res+=(L->second-1)*(L->second)>>1;
        }
        return res;
    }
};
int main(int argc,char* argv[]){
    vector<int> time={30,20,150,100,40};
    cout<<Solution().numPairsDivisibleBy601(time)<<endl;
    return 0;
}