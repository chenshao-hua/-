
Three stones are on a number line at position a,b,and c.Each turn,you pick up  stone at an
endpoint (ie.,either the lowest or highest position stone),and move it to an unoccupied 
position between those endpoints.Formally,let's say the stones are currently at positions x,
y,z with x< y < z.You pick up the stone at either position x or position z,and move that stone to an integer position x or position z,and move that stone to an integer position k,with x< y < z and k!=y.
The game ends when you cannot make any more moves,ie.the stones are in consecutive positions.
When the game ends,what is the minimum and maximumum number of moves that you could have made?
Return the answer as an length 2 array:answer=[minimum_moves,maximum_moves].

Example 1:
Input: a=1, b=2, c=5
Output: [1,2]
Explanation: Move the stone from 5 to 3, or move the stone from 5 to 4 to 3.

Example 2:
Input: a=4, b=3, c=2
Output: [0,0]
Explanation: We cannot make any moves.

Example 3:
Input: a=3, b=5, c=1
Output: [1,2]
Explanation: Move the stone from 1 to 4; or move the stone from 1 to 2 to 4.

题目大意:
三枚石子放置在数轴上,位置分别为a,b,c.
每一回合,你可以从两端之一拿起一枚石子(位置最大或最小),并将其放入两端之间的任一空闲位置.形式上,假设这三枚石子当前
分别位于位置 x,y,z 且x< y< z.那么就可以从位置x或者是位置z拿起一枚石子,并将该石子移动到某一整数位置k处,其中
x< k < z且k!=y.
当你无法进行任何移动时,即这些石子的位置连续时,游戏结束.
要使游戏结束,你可以执行的最小和最大移动次数分别是多少?以长度为2的数组形式返回答案:answer=[minimum_moves, 
maximum_moves].

解题思路:
这道题每次回合只要移动坐标轴上的左右两边的那个数,而且不能等于中间的数,要使其向区间内部移动.可以利用一个数组先对其进行排序,根据结果考虑最小步数,只要满足最大和最小之差为1时,就直接返回结果{0,0},或相邻两者之差小于等于2时最小
的步数为1,否则为2.最大步数即为每次移动一个步数,直到不能移动为止,这是否其实只要最大值减去最小值-2.

算法优化,不需要数组.

