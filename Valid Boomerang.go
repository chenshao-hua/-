/*
A boomerang is a set of 3 points that are all distinct and not in a straight line.
Given a list of three points in the plane,return whether these points are a boomerang.

Example 1:
Input:[[1,1],[2,3],[3,2]]
Output:true

Example 2:
Input:[[1,1],[2,2],[3,3]]
Output:false

题目大意:
回旋镖定义为一组三个点,这些各点不相同且不在一条直线上,给出平面上这三个点组成的列表,判断这些点是否可以构成
回旋镖.

解题思路:
这是一道简单的数学题目.判断三点是否共线,只需要判断斜率是否相等.考虑到斜率可能为0,使用乘法,交叉进行相乘.
*/


package main

import "fmt"

func isBoomerang(points [][]int)bool{
	return (points[0][0]-points[1][0])*(points[0][1]-points[2][1])!=
		(points[0][0]-points[2][0])*(points[0][1]-points[1][1])
}
func main(){
	points:=[][]int{{1,1},{2,3},{3,2}}
	fmt.Println(isBoomerang(points))
}