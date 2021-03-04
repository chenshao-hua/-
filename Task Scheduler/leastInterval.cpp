/*
Given a char array representing tasks CPU need to do.It contains  capital letters A to Z 
where different letters represent different tasks.Tasks could be done without original 
order.Each task could be done in one interval.
For each interval,CPU could finish one task or just be idle.
However,there is a non-negative coolinginterval n that means between two same tasks,there 
must be at least n intervals
that CPU are doing different tasks or just bu idle.
You need to return the least number of intervals the CPU will take to finish all the given 
tasks.

Example 1:
Input:tasks=['A','A','A','B','B','B'],n=2
Output:8
Explanation: A->B->idle->A->B->idle->A->B.

Note:
1.The number of tasks is in the range [1,10000].
2.The integer n is in the range [0,100].

题目大意:这道题的意思给一个字符数组tasks,表示cpu需要执行的任务列表.每个字母代表不同种类的任务.任务可以以任意
顺序执行,而且可以在1个单位时间内完成.在任意1个单位时间内,cpu可以完成一个任务或者处于待命状态.然而,两个相同
任务之间必须有长度为n个单位的冷却时间.因此至少有连续n个单位时间内cpu在执行不同的任务或者处于待命状态.需要计算
完成所有任务所需要的最短时间.

解题思路:
这道题是规定在字母相同即相同任务之间至少间隔n个时间点.要实现处理任务时间最少,那么相同任务时间的间隔应尽可能的大,
不少于间隔n是最好的结果.这样的话先考虑字母个数最多的那个任务,先确定好次数多的任务,因为间隔的时间多,然后再安排那
些次数少的任务.比如任务A出现的次数为k,为最多的那个,这样用间隔n作为空位将每两个A分隔开,然后依次把低频的任务插
入到这些空位上,这样可以抵消相同的时间.
例如:
AAAABBBEEFFGG 3
任务A出现4次,为最多的那个,然后在每两个A之间插入3个空位,
A---A---A---A
AB--AB--AB--A (加入B)
ABE-ABE-AB--A (加入E)
ABEFABE-ABF-A (加入F,每次尽可能填满或者均匀填充)
ABEFABEGABFGA (加入G)

方法1:
可以设定一个数组ans,存储26个字母,统计各个字母出现的次数,先对数组进行排序
根据上面的案例可以发现这样的规律,假定字母A为出现最多次数为k,则sum=(k-1)*(n+1)+末尾A的后部分个数(包括A),
这里的n+1为n就是空位+A本身,统计末尾A的后部分也显得简单多了,若次数K只有一个即为1,若不止一个,则需要遍历次数与
A字母相同的个数有几个,为了方便起见直接利用ans[i]=k枚举即可.
比较tasks的长度原因,当任务刚好把空闲时间占满时,这两个是一样大的;当任务没占满时,肯定是cnt+(n+1)*(vec[0]-1) 
大;当任务占满空闲时间且还有多余任务时(也就是存在F时).肯定是task.size()大.

方法2:
建立一个优先队列,然后把统计好的个数都存入优先队列中,那么大的次数会在队列的前面.然后进行分块,每块能装n+1个任务,
装任务是从优先队列中取,每个任务中取一个,装入一个临时数组中,然后遍历取出任务,对于每一个任务,将其哈希表映射的次数
减1,如果减1后,次数仍大于0,则将此任务的次数再次排入队列中,遍历完后如果队列不为空,说明该块全部被填满,
则结果加上n+1.在队列中取任务是用变量cnt来记录取出任务的个数,若想取出n+1个,如果队列中的任务少于n+1个,那就用cnt
来记录真实取出的个数,当队列为空时,就加上cnt的个数

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution{
public:
    int leastInterval(vector<char>& tasks,int n){
        vector<int> ans(26,0);
        for(auto& t:tasks){
            ++ans[t-'A'];
        }
        sort(ans.begin(),ans.end(),greater<int>());//降序排列
        int i=1,k=ans[0],len=(k-1)*(n+1)+1;
        while(i<26&&k==ans[i]){
            len++;//枚举末端A的后面部分
            i++;
        }
        int m=tasks.size();
        //在填不满桶时,最短时间为(n+1)*(max-1)+maxCount,
        //也就是桶的大小;在桶放不下时,最短时间是tasks.length,因为根据公式的插空法,刚好所有的元素都能插入,这样
        //就不需要间隔时间n了.
        return max(m,len);//不能小于tasks的长度
    }

    int leastIntervalOne(vector<char>& tasks,int n){
        int res=0,cycle=n+1;
        unordered_map<char,int> m;
        priority_queue<int> q;
        for(char t:tasks){
            ++m[t];
        }

        for(auto& i:m){
            q.push(i.second);
        }

        while(!q.empty()){
            int cnt=0;
            vector<int> t;
            for(int i=0;i<cycle;i++){
                if(!q.empty()){
                    t.push_back(q.top());
                    q.pop();
                    ++cnt;
                }
            }

            for(int d:t){
                if(--d>0){
                    q.push(d);
                }
            }
            res+=q.empty()?cnt:cycle;
        }
        return res;
    }
};

int main(int argc,char* argv[]){
    vector<char> tasks={'A','A','A','B','B','B'};
    int n=2;
    cout<<Solution().leastInterval(tasks,n)<<endl;
    cout<<Solution().leastIntervalOne(tasks,n)<<endl;
    return 0;
}