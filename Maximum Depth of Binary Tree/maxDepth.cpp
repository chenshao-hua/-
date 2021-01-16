/*
求一颗二叉树的最大深度.
方法1:
层次遍历法,bfs,利用队列先进先出的思想.
方法2:
递归法,dfs
*/
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct TreeNode{
private: 
    int val;
public:    
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

class Solution{
public:
    int maxDepth(TreeNode* root){
        return root?1+max(maxDepth(root->left),maxDepth(root->right)):0;
    }
    int bfsDepth(TreeNode* root){
        queue<TreeNode*> node{{root}};
        int count=0,n=1;
        while(!node.empty()){
            n=node.size();
            for(int i=0;i<n;i++){
                if(node.front()->left!=nullptr){
                    node.push(node.front()->left);
                }
                if(node.front()->right!=nullptr){
                    node.push(node.front()->right);
                }
                node.pop();
            }
            count++;
        }
        return count;
    }
};

int main(int argc,char* argv[]){
    TreeNode root(3);
    TreeNode ln1(9);
    TreeNode rn1(20);
    TreeNode rn21(15);
    TreeNode rn22(7);
    root.left=&ln1;
    root.right=&rn1;
    rn1.left=&rn21;
    rn1.right=&rn22;
    cout<<Solution().bfsDepth(&root)<<endl;
    return 0;
}