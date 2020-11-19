/*
利用key-value键值对，然后把错位词的字符顺序重新排列，这样就可以得到相同的结果，
因此重新排序是判断是否互为错位词的方法，由于错位词重新排序后都会得到相同的字符串，
所以可以以此为key，将所有错位词都保存到字符串数组中，建立key和字符串数组的映射，
最后再存入结果reuslt中即可.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
 
class Solution{
public:
    Solution(vector<string>& _strs):strs(_strs){}
    vector<vector<string>> groupAnagramrams(){
        vector<vector<string>> result;
        unordered_map<string,vector<string>> dictionary;
        for(auto& str:strs){
            string temp=str;
            sort(temp.begin(),temp.end());
            dictionary[temp].push_back(str);
        }
        for(auto& value:dictionary){
            result.push_back(value.second);
        }
        return result;
    }

 private:
    vector<string> strs;
};


int main(int argc,char* argv[]){
    vector<string> strs={"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result=Solution(strs).groupAnagramrams();
    for_each(result.begin(),result.end(),[](vector<string>& m){
        for(auto& str:m)
           cout<<str<<" ";
        cout<<endl;
    });
    return 0;
}