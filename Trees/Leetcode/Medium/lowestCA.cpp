//Leetcode Medium 235: Find the lowest common ancestor of two given nodes in a Binary Search Tree
//The question specifies that each node can also act as it's decendant. 
//Note that the lowest ancestor means lowest in depth from the root and not lowest in the actual value of the node
//Concept: We have access to the root, p and q where p and q are the two nodes whose common ancestor is to be found. We can utilize the properties of a BST in which each parent has it's left child lesser that it and it's right child greater than it. The node we want is to be in between p and q, or in other words, we traverse left when the current node is greater than both p and q, or we travel right if the current node is less than p and q. There is no guarantee that the p<q so we cannot check if the current node is >=p and <=q. Now, due to the aforementioned property of a BST, the first node we find in between p and q, will be the lowest common ancestor of p and q.
//Traversal can be done recursively
#include <iostream>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL ){
            return NULL;
        }
        TreeNode *cur=root;
        if(cur->val > p->val && cur->val > q->val)
        return lowestCommonAncestor(cur->left,p,q);
        if(cur->val < p->val && cur->val < q->val)
        return lowestCommonAncestor(cur->right,p,q);
        return cur;
    }
};
