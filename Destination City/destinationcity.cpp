/*
You are given the array paths,where paths[i]=[cityAi,cityBi] means there exists 
a direct path going from cityAi to cityBi.Return the destination city,that is,
the city without any outgoing to another city.
It is guaranteed that the graph of paths forms a line without any loop,
therefore,there will be exactly one destination city.

Example 1:
Input:paths=[["London","New York"],["New York","Lima"],["Lima","Sao Paulo"]]
Output:"Sao Paulo" 
Explanation:Starting at "London" city you will reach "Sao Paulo" city which is the destination city. Your trip consist of: "London" -> "New York" -> "Lima" -> "Sao Paulo".

Example 2:
Input: paths=[["B","C"],["D","B"],["C","A"]]
Output:"A"
Explanation:All possible trips are: 
"D" -> "B" -> "C" -> "A". 
"B" -> "C" -> "A". 
"C" -> "A". 
"A". 
Clearly the destination city is "A".

解题思路:
这道题刚开始没读懂题意,深思后,才意识到只需要找出最终点,因此先用数组存储第二点,
然后遍历paths的是否存在该第一点.用map可能更快
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution{
public:
    string destcity(vector<vector<string>>& paths){
#if 0
        vector<string> board;
        for(auto i=0;i<paths.size();i++)
           board.push_back(paths[i][1]);
        for(auto i=0;i<paths.size();i++){
            auto it=find(board.begin(),board.end(),paths[i][0]);
            if(it!=board.end())
               board.erase(it);
        }
        return board[0];
#endif
        map<string,string> ans;
        for(auto& i:paths)
             ans.insert(make_pair(i[0],i[1]));
        string key=paths[0][0];
        while(ans.find(key)!=ans.end()){
            key=ans[key];
        }
        return key;
    }
};
int main(int argc,char* argv[]){
    vector<vector<string>> paths={{"B","C"},{"D","B"},{"C","A"}};
    cout<<Solution().destcity(paths)<<endl;
    return 0;
}