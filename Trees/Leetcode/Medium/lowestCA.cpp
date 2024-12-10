//Leetcode Medium 235: Find the lowest common ancestor of two given nodes in a Binary Search Tree
//The question specifies that each node can also act as it's decendant. 
//Note that the lowest ancestor means lowest in depth from the root and not lowest in the actual value of the node
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
