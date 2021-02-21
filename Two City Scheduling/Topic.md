A company is planning to inerview 2n people.Given the array costs where 
costs[i]=[aCosti,bCosti],the cost of flying the ith person to city a is
aCosti,and the cost of flying the ith person to city b is bCosti.
Return the minimum cost of fly every person to a city such that exactly n people 
arrive in each city.

Example 1:
Input:costs=[[10,20],[30,200],[400,50],[30,20]]
Output:110
Explanation:
The first person goes to city A for a cost of 10.
The second person goes to city A for a cost of 30.
The third person goes to city B for a cost of 50.
The fourth person goes to city B for a cost of 20.
The total minimum cost is 10+30+50+20=110 to have half the people interviewing in each city.

Example 2:
Input:costs=[[259,770],[448,54],[926,667],[184,139],[840,118],[557,469]]
Output:1859
Explanation:
The total minimum cost is 259+54+667+184+118+557=1859 to have half the people interviewing 
in each city.

Example 3:
Input:costs=[[515,563],[451,713],[537,709],[343,819],[855,779],[457,60],[650,359],[631,42]]
Output:3086

题目大意:公司计划面试2n个人.第i人飞往A城市的费用是costs[i][0],飞往B城市的费用是costs[i][1],返回将每个人
都飞到某城市的最低费用,要求每个城市都有N个人抵达.

解题思路:
方法1:
写个递归算法,可惜超时.

方法2:
这道题关键点是在第i人在权衡A和B城市的两者之间的差值时达到最小,因此先利用map容器求出第i人的差值的绝对值,
根据multimap的降序排序,key值存储差值的绝对值,value存所在的index,枚举multimap,优先考虑差值大的,因为这
个影响着最低费用.最后分别考虑到达A和B城市的人数是否均为0.

方法3:
贪心算法
不用map,进行算法优化.
首先假设让所有人都去城市A,则总费用为去城市A的花费总和,考虑到需要一半的人去城市B,应该:若去城市B的花费小于城市
A的,则应该diff两者之间的差值,若去城市A的花费小于城市B的,则应该加上两者之间的差值.因此去城市B的减去去城市A的花费
,若为负数,则为diff,若为正数,则是追加的花费.当然希望是负数,而且越小越好.
整体的流程如下:
先假设都去A城市总费用ans,然后利用一个数组diff保存每个人的费用差值(去B城市的费用-去A城市的费用),然后对diff从小
到大进行排序,然后枚举diff数组前面一半部分+ans即为所求.

方法4:
官方做法,对于每个人的费用差:A城市的费用-B城市的费用,从小到到排序,然后枚举前半部分去A城市,后半部分去B城市