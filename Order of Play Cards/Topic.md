从扑克牌中随机抽5张牌,判断是不是一个顺子,即这5张牌是不是连续的.2～10为数字本身.A为1,J为11,Q为12,K为13,
而大、小王为0,可以看成任意数字.A不能视为14.

解题思路:
此题需要注意大小王的个数可能为5,因为没限制扑克牌的副数.

方法1:
set+遍历
(1)遍历5张牌,若遇到num[i]为0的牌,直接continue;
(2)利用两个变量Max,Min分别统计数组中的最大值和最小值;
(3)考虑到数组中可能存在非零的重复元素,根据insert的返回值,可以判断是否出现重复的元素,若存在,则直接return 
false.
(4)最终根据Max-Min的值是否小于等于4,判断是否为顺子.因为若为顺子,最大可能情况之差为4,例如:1、2、3、4、5;

方法2:
排序+遍历
(1)先对数组进行排序;
(2)利用一个变量n统计大小王的个数;
(3)判断重复非零元素:nums[i]==nums[i+1]
(4)最大元素为nums[4]-最小元素为nums[n],需要提出零元素.