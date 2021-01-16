/*
题目描述:
在无向图找出一条边,移除它之后该图能够成为一棵树(即无向无环图).如果有多个解,返回在原数组中位置最靠后的那条边.

Example 1:
Input:[[1,2],[1,3],[2,3]]
Output:[2,3]

解题思路:
因为需要判断是否两个节点被重复连通.所以可以使用并查集来解决此类问题.
*/
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;
class UF{
    vector<int> id;
public:
    UF(int n):id(n){
        iota(id.begin(),id.end(),0);/*初始化数组,值从0到n-1*/
    }
    int find(int p){
        while(p!=id[p]){
            p=id[p];
        }
        return p;
    }
    void connect(int p,int q){
        id[find(p)]=find(q);
    }
    bool isConnected(int p,int q){
        return find(p)==find(q);
    }
};

class Solution{
    public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges){
        int n=edges.size();
        UF uf(n+1);
        for(auto& e:edges){
            int u=e[0],v=e[1];
            if(uf.isConnected(u,v)){
                return e;
            }
            uf.connect(u,v);
        }
        return vector<int>{-1,-1};
    }
};

int main(int argc,char* argv[]){
    vector<vector<int>> edges={{1,2},{1,3},{2,3}};
    vector<int> ans=Solution().findRedundantConnection(edges);
    for(auto& num:ans){
        cout<<num<<endl;
    }
    return 0;
}