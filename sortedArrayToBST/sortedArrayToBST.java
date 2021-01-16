package sortedArrayToBST;/*
* 给定一个有序整数数组,元素各不相同且按升序排列,编写一个算法,创建一颗高度最小的二叉搜索数.
* Example 1:
* Input:let a sorted array:[-10,-3,0,5,9]
* Output:maybe [0,-3,9,-10,null,5]
*
* 为什么求中位数使用mid=(high-low)/2+low而不是使用mid=(low+high)/2
int是有限制范围的,(low+high)可能超出int的范围
* */

import java.util.LinkedList;

class Treenode{
    int val;
    Treenode left;
    Treenode right;
    Treenode(int _val){
        val=_val;
        left=null;
        right=null;
    }
    Treenode(int _val,Treenode _left,Treenode _right){
        val=_val;
        left=_left;
        right=_right;
    }
}
public class sortedArrayToBST {
    public Treenode sortedArrayToBT(int[] nums){
        return helper(nums,0,nums.length-1);
    }
    private Treenode helper(int[] nums,int low,int high){
        if(low>high)
            return null;/*表示子树为空*/
        int mid=(high-low)/2+low;/*根节点*/
        Treenode root=new Treenode(nums[mid]);

        root.left=helper(nums,low,mid-1);/*构建左子树*/
        root.right=helper(nums,mid+1,high);/*构建右子树*/
        return root;
    }

    public static void main(String[] args){
        int[] nums={-10,-3,0,5,9};
        sortedArrayToBST BST=new sortedArrayToBST();
        Treenode root=BST.sortedArrayToBT(nums),node;
        /*bfs遍历*/
        LinkedList<Treenode> list=new LinkedList<>();
        list.add(root);
        while(!list.isEmpty()){
            node=list.poll();/*出队*/
            System.out.println(node.val);
            if(node.left!=null){
                list.add(node.left);
            }
            if(node.right!=null){
                list.add(node.right);
            }
        }
    }
}
