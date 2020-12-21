/*
You are given four integers,m,n,introvertsCount,and extrovertsCount.You have an mxn grid ,and 
there are two types of people: introverts and extroverts.There are introvertsCount introverts 
and extrovertsCount extroverts.
You should decide how many people you want to live in the grid and assign each of them one 
grid cell.Note that you do not have to have all the people living in the grid.

The happiness of each person is calculated as follows:
（1）Introverts start with 120 happiness and lose 30 happiness for each neighbor(introvert or
 extrovert).
（2）Extroverts start with 40 happiness and gain 20 happiness for each neighbor(introvert or extrovert).
Neighbors live in the directly adjacent cells north,east,south,and west of a person's cell.
The grid happiness is the sum of each person's happiness.Return the maximum possible grid happiness.

Input: m=2, n=3, introvertsCount=1, extrovertsCount=2
Output: 240
Explanation:Assume the grid is 1-indexed with coordinates (row, column).
We can put the introvert in cell (1,1) and put the extroverts in cells (1,3) and (2,3).
-Introvert at (1,1) happiness:120(starting happiness)-(0*30)(0 neighbors)=120
-Extrovert at (1,3) happiness:40(starting happiness)+(1*20)(1 neighbor)=60
-Extrovert at (2,3) happiness:40(starting happiness)+(1*20)(1 neighbor)=60
The grid happiness is 120 + 60 + 60 = 240.
The above figure shows the grid in this example with each person's happiness.The introvert stays in 
the light green cell while the extroverts live on the light purple cells.

解题思路:按行进行状态压缩
三进制:0、1、2,分别表示空、内向、外向
以行为单位进行动态规划,可以将其分成两个部分:
（1）同一行内分数:在同一行内每个人的分数,内向120分,外向40分;以及由于两个人相邻(下同一行内,即左右相邻)
贡献的额外分数,两个内向-60分,两个外向40分,其余情况为-10分;
（2）上下行外分数:由于两人相邻(在不同行内,即上下相邻)贡献的额外分数,同理为-60,-40,-10分中的一种.
如果规定[上下行外分数]由相邻两行中的后一行负责计算,那么在枚举当前行对应的三进制表示mask时,就需要计算其
与前一行之间的[上下行外分数],因此可以设计出动态规划中的状态:
令f(mask,row,nx,wx)表示当我们枚举到第row行且之前的行已经枚举完成,第row-1行状态为mask,还剩余nx个
内向的人以及wx个外向的人的情况下,从row行开始往后的所有行可以获取的最大行数.其状态转移方程为:
f(mask,row,nx,wx)=max{f(mask,row+1,nx-countnx(mask),wx-countwx(mask))+scoreinner(mask)+scoreouter(mask)}
countnx/wx(mask)表示状态马赛克有多少内向的人/外向的人
（1）每一个mask对应的三进制表示，存放在数组mask_span中;
（2）countnx(mask)和countwx(mask)分别存在数组nx_inner和wx_inner;

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

class Solution{
private:
    int mask_span[729][6];/*预处理,每一个mask的三进制*/
    int dp[729][6][7][7];/*dp[上一行的mask][当前处理到的行][剩余的内向人数][剩余的外向人数]*/
    int nx_inner[729],wx_inner[729],score_inner[729],score_outer[729][729];/*每一个mask包含的内向人数,外向人数,行内得分(只统计mask本身的得分,不包括它与上一行的),行外得分*/
    int m,n,n3;/*n3=3^n*/
private:
    /*x与y的邻近关系*/
    inline int calc(int x,int y){
        if(x==0||y==0)
           return 0;
        if(x==1&&y==1)
           return -60;
        if(x==2&&y==2)
           return 40;
        return -10;
    }
    
    int dfs(int mask_last,int row,int nx,int wx){
        /*处理完或者没人*/
        if(row==m||nx+wx==0)
           return 0;
        if(dp[mask_last][row][nx][wx]!=-1)
           return dp[mask_last][row][nx][wx];
        int best=0;
        for(int mask=0;mask<n3;++mask){
            if(nx_inner[mask]>nx||wx_inner[mask]>wx)
               continue;
            int score=score_inner[mask]+score_outer[mask][mask_last];
            best=max(best,score+dfs(mask,row+1,nx-nx_inner[mask],wx-wx_inner[mask]));
        }
        return dp[mask_last][row][nx][wx]=best;
    }
public:
    int getMaxGridHappiness(int m,int n,int nx,int wx){
        this->m=m;
        this->n=n;
        this->n3=pow(3,n);
        for(int mask=0;mask<n3;mask++){
            for(int mask_tmp=mask,i=0;i<n;i++){
                mask_span[mask][i]=mask_tmp%3;
                mask_tmp/=3;
            }
            nx_inner[mask]=wx_inner[mask]=score_inner[mask]=0;
            for(int i=0;i<n;i++){
                if(mask_span[mask][i]!=0){
                    /*个人分数*/
                    if(mask_span[mask][i]==1){
                        nx_inner[mask]++;
                        score_inner[mask]+=120;
                    }else if(mask_span[mask][i]==2){
                        wx_inner[mask]++;
                        score_inner[mask]+=40;
                    }
                    /*行内分数*/
                    if(i-1>=0){
                        score_inner[mask]+=calc(mask_span[mask][i],mask_span[mask][i-1]);
                    }
                }
            }
        }
        /*行外分数*/
        for(int mask0=0;mask0<n3;mask0++){
            for(int mask1=0;mask1<n3;mask1++){
                score_outer[mask0][mask1]=0;
                for(int i=0;i<n;i++){
                    score_outer[mask0][mask1]+=calc(mask_span[mask0][i],mask_span[mask1][i]);
                }
            }
        }
        memset(dp,-1,sizeof(dp));
        return dfs(0,0,nx,wx);
    }
};
int main(int argc,char* argv[]){
    cout<<Solution().getMaxGridHappiness(2,3,1,2)<<endl;
    return 0;
}