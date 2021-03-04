Given an array nums of n integers,are there elements a,b,c in nums such that a+b+c=0?Find all 
unique triplets in the array which gives the sum of zero.
Notice that the solution set must not contain duplicate triplets.

Example 1:

Input: nums=[-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]

Example 2:
Input: nums=[]
Output: []

Example 3:
Input: nums=[0]
Output: []


题目大意:
给定一个整数数组nums,找出所有和为0且不重复的三元组.

解题思路:
双指针
设置3个指针,最左的指针为k,k的右端部分2个指针分别为i、j,范围为（k,len(nums)),通过移动i、j双指针向中间靠拢,记录对
于每 次枚举固定指针k的满足nuns[k]+nums[i]+nums[j}=0的i、j的所有可能组合.
（1）当nums[k]>0时,直接退出最外层循环,因为此时必定nums[j]>=nums[i]>=nums[k]>0,即3个元素都大于0.
（2）当k>0且nums[k]=nums[k-1]时,即可以跳过此元素nums[k],因为nums[k-1]所有的组合已经加入到结果中,这样会出现重复
结果.
（3）i、j分别设置为（k,len(nums)）左右两端,当i<j时需要考虑以下条件:
a.当sum<0时,i++,需要考虑到所有重复的元素nums[i],若重复需跳过;
b.当sum>0时,j--,需要考虑到所有重复的nums[j],若重复需跳过;
c.当sum=0时,记录组合[k,i,j],并且进行i++,j++并且考虑到所有重复的元素nums[i]和nums[j],若重复需跳过.