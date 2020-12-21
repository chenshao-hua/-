/*
There is a stream of n (id,value) pairs arriving in an arbtrary order,where id is
 an integer between 1 and n and value is a string.No two pairs have the same id. 
Design a stream that returns the values in increasing order of their IDs by 
returning a chunk(list) of values after each insertion.The concatenation of
 all the chunks should result in a list of the sorted values.
Implement the OrederedStream class:
（1）OrderedStream(int n) Constructs the stream to take n values.
（2）String[] insert(int id,String value) Inserts the pairr(id,value) into 
the stream,then returns the largest possible chunk of currentlty inserted 
values that appear next in the order.

Example 1:
Input:
["OrderedStream","insert","insert","insert","insert","insert"]
[[5],[3,"ccccc"],[1,"aaaaa"],[2,"bbbbb"],[5,"eeeee"],[4,"ddddd"]]
Output:
[null,[],["aaaaa"],["bbbbb","ccccc"],[],["ddddd","eeeee"]]

解题思路:
这道题比较简单,关键是理解题目,先用一个数组存储插入的值,然后通过循环判断
插入的id是否与目标指针相等

*/
#include <iostream>
#include <vector>

using namespace std;

class OrderedStream{
public:
    OrderedStream(int n):ptr(1),str(n+1){}
    vector<string> insert(int id, string value){
        vector<string> ans;
        ans.clear();
        str[id]=value;
        while(id==ptr){
            if(ptr>=str.size()||str[ptr].empty())
               break;          
            ans.push_back(str[ptr]);
            ptr++;
            id++;         
        }/*可以省略id++和if的判断,条件循环换成:ptr<str.size()&&str[ptr].lenghth()>0*/
        return ans;
    }
private:
    int ptr;
    vector<string> str;
};

int main(int argc,char* argv[]){
    OrderedStream* ordered=new OrderedStream(5);
    vector<pair<int,string>> nums={{3,"ccccc"},{1,"aaaaa"},{2,"bbbbb"},{5,"eeeee"},{4,"ddddd"}};
    for(auto& n:nums){
        vector<string> ans=ordered->insert(n.first,n.second);
        for(auto& i:ans)
            cout<<i<<" ";
        cout<<endl;
    }

    delete ordered;
    return 0;
}