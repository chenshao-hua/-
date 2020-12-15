/*
Given a binary tree,find its maximum depth.
The maximum depth is the number of nodes along the longest path from the root node down to
the farthest leaf node.
Note:A leaf is a node with no children.

Example 1:
Input:[3,9,20,null,null,15,7]
Output:3

解题思路:
利用递归遍历即可,从根节点的左孩子的高度和根节点右孩子的高度,取出两者的最大值再加1便可以得到树的高度.
迭代法也可以做
*/
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct treenode{

    treenode* left;
    treenode* right;
    treenode(const int& _val):val(_val),left(nullptr),right(nullptr){}
private:
    const int val;
};

class Solution{
public:
    int maxdepthoftree(treenode* root){
        if(root==nullptr)
            return 0;
        return max(maxdepthoftree(root->left),maxdepthoftree(root->right))+1;
    }
    int maxoftree(treenode* root){
        if(root==nullptr)
            return 0;
        auto depth=0;
        queue<treenode*> node{{root}};
        while(!node.empty()){
            depth++;
            for(auto i=node.size();i>0;i--){
                treenode* q=node.front();
                node.pop();
                if(q->left)
                   node.push(q->left);
                if(q->right)
                   node.push(q->right);
            }
        }
    }
};

int main(int argc ,char* argv[]){
    treenode root(3);
    treenode node1(9),node2(20),node3(15),node4(7);
    root.left=&node1;
    root.right=&node2;
    node2.left=&node3;
    node2.right=&node4;
    cout<<Solution().maxdepthoftree(&root)<<endl;
    cout<<Solution().maxdepthoftree(&root)<<endl;
    return 0;
}