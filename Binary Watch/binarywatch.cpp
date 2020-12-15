/*
A binary watch has 4 LEDs on the top which represent the hours(0-11),
and the 6 LEDs on the bottom represent the minutes(0-59).

Each LED represents a zero or one,with the least siganification bit on 
the right.

For example,the above binary watch reads "3:25".

Given a non_negative integer n which represents the number of LEDs that
are currently on,return all possible times the watch would could represent.

Example 1:
Input:1
Output: ["1:00","2:00","4:00","8:00","0:01","0:02","0:04","0:08","0:16","0:32"]

The order of output does not matter.
The hour must not contain a leading zero, for example "01:00" is not valid, it
should be "1:00".
The minute must be consist of two digits and may contain a leading zero, for 
example "10:2" is not valid, it should be "10:02".

解题思路:
参考LeetCode的一位大神,使用两层遍历,然后利用二进制转换结果与目标值进行对比.此外可以直接通过,
bitset<10>((i<<6)|j).count()==num,就可以省略digittonum函数.
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution{
public:
    vector<string> readBinaryWatch(const int& num){
        vector<string> res;
        for(auto i=0;i<12;i++){
            for(auto j=0;j<60;j++){
                if(digittonum(i)+digittonum(j)==num){
                    res.push_back(to_string(i)+":"+(j<10?"0"+to_string(j):to_string(j)));
                }
            }
        }
        return res;
    }
private:
    int digittonum(int a){
        int num=0;
        while(a){
            a=a&(a-1);
            num++;
        }
        return num;
    }
};

int main(int argc,char* argv[]){
    const int num=2;
    vector<string> res=Solution().readBinaryWatch(num);
    for(auto& i:res)
       cout<<i<<endl;
    return 0;
}