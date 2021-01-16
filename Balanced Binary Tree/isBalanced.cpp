/*
判断一个二叉树是否平衡.树平衡的定义是,对于树上的任意节点,其左右两侧的子树高度差的绝对值不超过1.
解题:
方法1:
根据左右两侧的子树高度差,可以推测出只要求出这棵树的最大高度与最小高度之间的差值是否满足不超过1,
这样就可以判断出是否是平衡二叉树.

方法2:
后序遍历,需要先处理子树的深度再进行比较,如果在处理过程中发现其已经不平衡了,则可以返回一个-1;
*/
#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode{
private:
    int val;
public:
    TreeNode* left;
    TreeNode* right;
    TreeNode(int _val):val(_val),left(nullptr),right(nullptr){}
    TreeNode(int _val,TreeNode* _left,TreeNode* _right){
        val=_val;
        left=_left;
        right=_right;
    }
};

class Solution{
public:
    bool isBalanced(TreeNode* root){
        if(root==nullptr) return true;
        return abs(depth(root->left)-depth(root->right))<=1&&isBalanced(root->left)&&isBalanced(root->right);
    }

    bool Isbalanced(TreeNode* root){
        return helper(root)!=-1;
    }
private:
    int depth(TreeNode* root){
        if(root==nullptr) 
           return 0;
        return 1+max(depth(root->left),depth(root->right));
    }

    /*辅助*/
    int helper(TreeNode* root){
        if(!root) return 0;
        int left=helper(root->left),right=helper(root->right);
        if(left==-1||right==-1||abs(left-right)>1)
           return -1;
        return 1+max(left,right);
    }
};
int main(int argc,char* argv[]){
    TreeNode rn32(12);
    TreeNode rn21(15);
    TreeNode rn22(7,nullptr,&rn32);
    TreeNode ln21(10);
    TreeNode ln1(9,&ln21,nullptr);
    TreeNode rn1(20,&rn21,&rn22);
    TreeNode root(3,&ln1,&rn1);
    cout<<Solution().Isbalanced(&root)<<endl;
    return 0;
}