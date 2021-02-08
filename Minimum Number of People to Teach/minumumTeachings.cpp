/*
On a social network consisting of m users and some friendships between users,two users can 
comminucate with each other if they know a common language.
You are given an integer n, an array languages, and an array friendships where:
(1)There are n languages numbered 1 through n.
(2)languages[i] is the set of languages the ith user knows, and friendships[i]=[ui,vi] 
denotes a friendship between the users ui and vi.
You can choose one language and teach it to some users so that all friends can comminicate
with each other.Return the minimum number of users you need to teach.
Note that friendships are not transitive,meaning if x is a friend of y and y is a friend of 
z,this doesn't guarantee that x is a friend of z.

Example 1:
Input: n=2, languages=[[1],[2],[1,2]], friendships=[[1,2],[1,3],[2,3]]
Output: 1
Explanation:You can either teach user 1 the second language or user 2 the first language.

Example 2:
Input: n=3, languages=[[2],[1,3],[1,2],[3]], friendships=[[1,4],[1,2],[3,4],[2,3]]
Output: 2
Explanation:Teach the third language to users 1 and 3, yielding two users to teach.


题目大意:
在一个由m个用户组成的社交网络里,获取到一些用户之间的好友关系.两个用户之间可以相互沟通的条件就是拥有相同的语言.
给你一个整数n,数组languages和数组friendships.
你可以选择一门语言并教会一些用户,使得所有好友之间都可以相互沟通.请返回你最少需要教会多少名用户.

解题思路:
这道题显而易见,首先需要找出那些好友没有公共的语言,其次需要学习一种语言,这就意味着那些没有共同语言的好友一定会
通过学习某种语言建立联系.因为只能选择一种语言,那么选出的这个语言如果会的人多则是一种最优解.无共同语言的好友的
数量减去会最多语言的数量,就是需要学习该语言的人数.
把掌握相同语言的人放到一个集合中,利用unordered_map数组存储,key对于的是一种语言,value对于unordered_set
掌握相同语言的人.然后枚举friendships数组中每两个用户之间的关系.
*/
#include <iostream>
#include <unordered_set>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution{
public:
    int minmunTeachings(int n,vector<vector<int>>& languages,vector<vector<int>>& friendships){
        int ans=0;
        /*
        unordered_map<int,unordered_set<int>> can_lang;//统计会的语言
        for(int i=0;i<languages.size();++i){
            for(auto j:languages[i])
                can_lang[j].insert(i+1);//i+1代表第几号用户,大于0的
        }

        set<int> notcomm;//不会交流的用户
        for(int i=0;i<friendships.size();++i){
            int p1=friendships[i][0],p2=friendships[i][1];
            for(auto can:can_lang){         
                if(can.second.count(p1)&&can.second.count(p2))
                    continue;
                else{
                    //不能沟通
                    notcomm.insert(p1);
                    notcomm.insert(p2);
                }   
            }
        }
        */

       unordered_set<int> notconnect;
       //记录没有公共语言的
       for(auto p:friendships){
           if(!hascommon(languages,p[0],p[1])){
               notconnect.insert(p[0]);
               notconnect.insert(p[1]);
           }
       }
        unordered_map<int,int> mostlang;//统计最多语言个数
        for(auto i:notconnect){
            for(auto j:languages[i-1]){
                mostlang[j]++;   
            }
        }
        
        for(auto k:mostlang){
            ans=max(ans,k.second);
        }
        return notconnect.size()-ans;
    }

private:
    bool hascommon(vector<vector<int>>& lang,int i,int j){
        for(auto p1:lang[i-1]){
            for(auto p2:lang[j-1]){  
                if(p1==p2)  return true;
            }
        }
        return false;
    }
};

int main(int argc,char* argv[]){
    vector<vector<int>> languages={{2},{1,3},{1,2},{3}},friendships={{1,4},{1,2},{3,4},{2,3}};
    cout<<Solution().minmunTeachings(3,languages,friendships)<<endl;
    return 0;
}