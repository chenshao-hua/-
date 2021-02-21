#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int ans=0,k=0,A=costs.size()>>1,B=costs.size()>>1;
        multimap<int,int,greater<int>> board;//降序排序,multimap没有下标索引
        for(auto& cost:costs){
            board.insert(make_pair(abs(cost[0]-cost[1]),k++));
        }
        // for(auto b:board){
        //     cout<<b.first<<" "<<b.second<<endl;
        // }
        auto i=board.begin();
        while(i!=board.end()){
            if(A==0||B==0) break;
            if(costs[i->second][0]>costs[i->second][1]){
                B--;
                ans+=costs[i->second][1];
            }else{
                A--;
                ans+=costs[i->second][0];
            }
            i++;
        }
        //A不为0时
        for(;i!=board.end()&&A!=0;i++,A--){
            ans+=costs[i->second][0];
        }
        //B不为0时
        for(;i!=board.end()&&B!=0;i++,B--){
            ans+=costs[i->second][1];
        }
        return ans;
    }

    int twoCitySchedCostOne(vector<vector<int>>& costs) {
        int ans=0;
        vector<int> diff;
        for(auto& cost:costs){
            ans+=cost[0];
            diff.push_back(cost[1]-cost[0]);
        }
        sort(diff.begin(),diff.end(),less<int>());//从小到大排序,可以省略less
        for(int i=0;i<diff.size()/2;i++){
            ans+=diff[i];
        }
        return ans;
    }

    int twoCitySchedCostTwo(vector<vector<int>>& costs) {
        sort(costs.begin(),costs.end(),[&](vector<int>& A,vector<int>& B){
            return A[0]-A[1]<B[0]-B[1];
        });
        int ans=0,n=costs.size()>>1;
        for(int i=0;i<n;i++){
            ans+=costs[i][0]+costs[i+n][1];
        }
        return ans;
    }
};

int main(int argc,char* argv[]){
    vector<vector<int>> costs={{259,770},{448,54},{926,667},{184,139},{840,118},{577,469}};
    cout<<Solution().twoCitySchedCost(costs)<<endl;
    cout<<Solution().twoCitySchedCostOne(costs)<<endl;
    return 0;
}