You have n gardens,labeled from 1 to n,and an array paths where paths[i]=[xi,yi] describes a 
biddirectional path between garden xi to garden yi.In each garden,you want to plant one of 4
types of flowers.
All gardens have at most 3 paths coming into or leaving it.
Your task is to chooose a flower type for each garden such that,for any two gardens connected
by a path ,they have different types of flowers.
Return any such a choice as an array * answer,where answer[i] is the type of flower planted 
in the (i+1)th garden.The flower types are denoted 1,2,3,or 4.It is guaranteed an answer 
exists.*

Example 1:
Input: n=3, paths=[[1,2],[2,3],[3,1]]
Output:[1,2,3]
Explanation:
Gardens 1 and 2 have different types.
Gardens 2 and 3 have different types.
Gardens 3 and 1 have different types.
Hence, [1,2,3] is a valid answer. Other valid answers include [1,2,4], [1,4,2], and [3,2,1].

Example 2:
Input: n=4, paths=[[1,2],[3,4]]
Output:[1,2,1,2]

Example 3:
Input: n=4, paths=[[1,2],[2,3],[3,4],[4,1],[1,3],[2,4]]
Output:[1,2,3,4]
 
题目大意:
有n个花园,按从1到n标记.另有数组paths,其中paths[i]=[xi,yi]描述了花园xi到花园yi的双向路径.在每个花园中,
你打算种下四种花之一.另外,所有花园最多有3条路径可以进入或离开.
你需要为每个花园选择一种花,使得通过路径相连的任何两个花园中的花的种类互不相同.
以数组形式返回任一可行的方案作为答案answer,其中 answer[i]为在第(i+1)个花园中种植的花的种类.花的种类用 
1、2、3、4表示.保证存在答案.

解题思路:
可以返回任意一个满足题意的结果.考虑到数组的长度可能比较大,可以利用邻接表,不用矩阵,根据paths建立邻接表,
然后从数组{1,2,3,4}中分别给花园进行种花,为了方便起见,先从相连的花园进行种花,然后对在剩余的花中选其中
一种进行种花,按照数组的顺序进行.以此类型,枚举所有花园的情况,并完成相应的种花情况,最终返回数组即为一个结果.

算法优化,可以不用set容器.