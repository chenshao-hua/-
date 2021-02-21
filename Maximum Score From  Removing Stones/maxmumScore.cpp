/*
You are playing a solitaire game with three piles of stones sizes a,b, and c respectively.
Each turn you chooose two different non-empty piles,take one stone from each,and add 1 point
to your score.The game stops when there are few than two-empty piles(meaning there are no 
more available moves).
Given three integers a,b, and c,return the maximum score you can get.

Example 1:
Input: a = 2, b = 4, c = 6
Output: 6
Explanation: The starting state is (2, 4, 6). One optimal set of moves is:
- Take from 1st and 3rd piles, state is now (1, 4, 5)
- Take from 1st and 3rd piles, state is now (0, 4, 4)
- Take from 2nd and 3rd piles, state is now (0, 3, 3)
- Take from 2nd and 3rd piles, state is now (0, 2, 2)
- Take from 2nd and 3rd piles, state is now (0, 1, 1)
- Take from 2nd and 3rd piles, state is now (0, 0, 0)
There are fewer than two non-empty piles, so the game ends. Total: 6 points.

Example 2:
Input: a = 4, b = 4, c = 6
Output: 7
Explanation: The starting state is (4, 4, 6). One optimal set of moves is:
- Take from 1st and 2nd piles, state is now (3, 3, 6)
- Take from 1st and 3rd piles, state is now (2, 3, 5)
- Take from 1st and 3rd piles, state is now (1, 3, 4)
- Take from 1st and 3rd piles, state is now (0, 3, 3)
- Take from 2nd and 3rd piles, state is now (0, 2, 2)
- Take from 2nd and 3rd piles, state is now (0, 1, 1)
- Take from 2nd and 3rd piles, state is now (0, 0, 0)
There are fewer than two non-empty piles, so the game ends. Total: 7 points.

Example 3:
Input: a = 1, b = 8, c = 8
Output: 8
Explanation: One optimal set of moves is to take from the 2nd and 3rd piles 
for 8 turns until they are empty.
After that, there are fewer than two non-empty piles, so the game ends.

题目大意:
放置a、b和c的三堆石子.每回和你都要从两个不同的非空堆中取出一颗石子,并且得分上加1分.当存在两个或更多的空堆时,
游戏结束.

解题思路:
贪心算法,要使得得分最多就要选择石子最多的那一堆,因此可以先对a,b,c进行简单的排序.接下来分组讨论:
(1)a+b<c时,那么最后剩余的石子的数量:c-a-b;
(2)a+b>=c时,每次取最多的那两堆石子,最后任意两堆石子不会相差超过1个石子,若石子总数为奇数时,则最后剩余1个
石子;若为偶数则,剩余0个石子;
*/

#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

class Solution{
public:
    int maximumScore(int a,int b,int c){
        array<int,3> num={a,b,c};
        sort(num.begin(),num.end());
        int k=0;
        if(num[0]+num[1]<num[2]){
            k=num[2]-num[0]-num[1];
        }else{
            k=(a+b+c)%2;
        }
        return (a+b+c-k)>>1;
    }
    int maximumScoreOne(int a,int b,int c){
        array<int,3> s{a,b,c};
        sort(s.begin(),s.end());
        int ans=0;
        while(s[1]&&s[2]){
            --s[1];
            --s[2];
            ++ans;
            sort(s.begin(),s.end());
        }
        return ans;
    }

};
int main(int argc,char* argv[]){
    cout<<Solution().maximumScore(4,6,8)<<endl;
    return 0;
}