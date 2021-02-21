#include <iostream>
#include <vector>
#include <algorithm>

using namespace  std;
class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> res{a,b,c};
        sort(res.begin(),res.end(),less<int>());
        int minNum=0,maxNum=0;
        if(res[2]-res[0]==2){
            return {minNum,maxNum};
        }
        if(res[1]-res[0]<=2||res[2]-res[1]<=2){
            minNum=1;
        }else{
            minNum=2;
        }
        maxNum=res[2]-res[0]-2;
        return {minNum,maxNum};
    }
    vector<int> numMovesStonesOne(int a, int b, int c) {
        int sum=a+b+c;
        int x=min(a,min(b,c));
        int z=max(a,max(b,c));
        int y=sum-x-z;
        int minNum=0;
        if(z-x==2){
            return {0,0};
        }
        if(y-x<=2||z-y<=2){
            minNum=1;
        }else{
            minNum=2;
        }
        return {minNum,z-x-2};
    }
};

int main(int argc,char* argv[]){
    vector<int> ans=Solution().numMovesStones(7,4,1);
    for(auto& a:ans){
        cout<<a<<" ";
    }
    cout<<endl;
    return 0;
}