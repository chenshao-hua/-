#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths){
        vector<vector<int>> Graph(n);//建立邻接表
        for(int i=0;i<paths.size();i++){
            Graph[paths[i][0]-1].push_back(paths[i][1]-1);
            Graph[paths[i][1]-1].push_back(paths[i][0]-1);
        }
        vector<int> ans(n,0);//存储结果,初始化全部花园未种花
        for(int i=0;i<n;i++){
            set<int> flowers{1,2,3,4};
            for(int j=0;j<Graph[i].size();j++){
                flowers.erase(ans[Graph[i][j]]);//移除相连花园已经种过的花
            }
            ans[i]=*(flowers.begin());//从剩余的花中任选一种,方便起见,选起始位置的
        }
        return ans;
    }
    vector<int> gardenNoAdjOne(int n, vector<vector<int>>& paths){
        vector<vector<int>> Graph(n);//建立邻接表
        for(int i=0;i<paths.size();i++){
            Graph[paths[i][0]-1].push_back(paths[i][1]-1);
            Graph[paths[i][1]-1].push_back(paths[i][0]-1);
        }
        vector<int> ans(n,0);//存储结果,初始化全部花园未种花
        //枚举所有花园开始种花 
        for(int i=0;i<n;i++){
            int flowers[4]={0};
            for(int j=0;j<Graph[i].size();j++){
                if(ans[Graph[i][j]-1]!=0)
                   flowers[ans[Graph[i][j]-1]-1]++;
            }

            for(int k=0;k<4;k++){//枚举已经种过的花,当第一种花没种过,直接进行种花
                if(flowers[k]==0){
                    ans[i]=k+1;//种花,+1代表花的种类,数字从1开始的
                    break;
                }
            }
        }
        return ans;
    }
};
int main(int argc,char* argv[]){
    vector<vector<int>>  paths={{1,2},{2,3},{3,1}};
    constexpr int n=3;
    vector<int> ans=Solution().gardenNoAdj(n,paths);
    for(auto& an:ans){
        cout<<an<<" ";
    }
    cout<<endl;
    return 0;
}