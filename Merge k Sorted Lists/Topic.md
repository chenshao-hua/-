You are given an array of k linked-lists,each linked-list is sorted in ascending order.
Merge all the linked-lists into one sorted linked-list and return it.

Example 1:
Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6

Example 2:
Input: lists = []
Output: []

Example 3:
Input: lists = [[]]
Output: []
 
题目大意:
给定k个增序的链表,试将它们合并成一条增序链表.

解题思路:
方法1:
枚举数组中所有链表的元素,存储在一个数组中,然后进行排序,即可.时间复杂度为O(n),空间复杂度也为O(n).

方法2:
分治思想,先每次拆分成k/2.最终再进行合并.

方法3:
优先队列.把所有的链表存储在一个优先队列中,每次提取所有链表头部节点值最小的那个节点,直到所有链表都被提取完.
需要设置一个比较类Comp,实现最小堆.因此operate()中返回时用大于号而不是等增关系的小于号进行比较.