/*
You are given a list schedule of employees,which represents the working time for each 
employee.Each employee has a list of non-overlapping Intervals,and these intervals are
in sorted order.Return the list of finite intervals representing common,positive-length 
free for all employees,alse in sorted order.

Example 1:
Input: schedule=[[[1,2],[5,6]],[[1,3]],[[4,10]]]
Output:[[3,4]]
Explanation:
There are a total of three employees, and all common
free time intervals would be [-inf, 1], [3, 4], [10, inf].
We discard any intervals that contain inf as they aren't finite.

Example 2:
Input: schedule=[[[1,3],[6,7]],[[2,4]],[[2,5],[9,12]]]
Output:[[5,6],[7,9]]

题目大意:
给定一组员工的工作时间,其中每个员工的工作时间是一组排好序的不相交的区间,要求输出所有员工都空闲的区间,不包含
首尾的无限区间.

解题思路:
方法一:
先拆分一维数组,然后进行排序(以start进行排序,若相等则以end排序,从小到大),最后枚举各个区间看是否重叠.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Interval{
    int start;
    int end;
    Interval():start(0),end(0){}
    Interval(int s,int e):start(s),end(e){}
};

// class MyCompare{
// public:
//     bool operator()(const Interval& a,const Interval& b){
//         return a.start==b.start?(a.end<b.end):(a.start<b.start);
//     }
// };

class Solution{
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>>& schedule){
        vector<Interval> board;
        for(auto& sch:schedule){
            for(auto& i:sch){
                board.push_back(i);
            }
        }
        //sort(board.begin(),board.end(),MyCompare());
        sort(board.begin(),board.end(),[](const Interval& a,const Interval& b){
            if(a.start==b.start){
                return a.end<b.end;
            }
            return a.start<b.start;
        });
        if(board.size()==1)  return vector<Interval>{};

        vector<Interval> ans;  
        int i=1,L=board[0].end;
        while(i<board.size()){
            if(board[i].start<=L){
                L=max(board[i].end,L);
            }else{
                ans.push_back({L,board[i].start});
                L=board[i].end;
            }
            i++;
        }

        // for(auto& an:board){
        //     cout<<"["<<an.start<<","<<an.end<<"]";
        // }
        // cout<<endl;
        // for(auto& an:ans){
        //     cout<<"["<<an.start<<","<<an.end<<"]";
        // }
        return ans;
    }
};

class Solution1{
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>>& schedule){
        if(schedule.empty()) return {};
        this->schedule=schedule;
        vector<Interval> result;
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare> pq;
        for(int i=0;i<schedule.size();i++){
            pq.push({i,0});
        }

        auto tmp=pq.top();
        int start=schedule[tmp.first][tmp.second].end;
        pq.pop();
        if(tmp.second+1<schedule[tmp.first].size()){
            pq.push({tmp.first,tmp.second+1});
        }

        while(!pq.empty()){
            tmp=pq.top();
            int tmp_start=schedule[tmp.first][tmp.second].start;
            if(tmp_start>start){
                result.push_back(Interval(start,tmp_start));
            }
            start=max(start,schedule[tmp.first][tmp.second].end);
            pq.pop();
            if(tmp.second+1<schedule[tmp.first].size()){
                pq.push({tmp.first,tmp.second+1});
            }
        }
        return result;
    }
private:
    inline static vector<vector<Interval>> schedule;
    struct compare{
        bool operator()(pair<int,int> a,pair<int,int> b){
            return schedule[a.first][a.second].start>schedule[b.first][b.second].start;
        }
    };
};

int main(int argc,char* argv[]){
    vector<vector<Interval>> schedule={{{1,2},{5,6}},{{1,3}},{{4,10}}};//{{{1,3},{6,7}},{{2,4}},{{2,5},{9,12}}};
    vector<Interval> ans=Solution().employeeFreeTime(schedule);
    for(auto& an:ans){
        cout<<"["<<an.start<<","<<an.end<<"]";
    }
    cout<<endl;
    return 0;
}