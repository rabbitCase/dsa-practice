//Leetcode Medium 236
//A node is an LCA if p and q both appear in its left and right subtrees and vice versa. When using recursion, we are searching bottom up, so the first node which satisfies the condition is our LCA. Also if we find one of nodes in one subtree and the other subtree returns null, then it means that the other node exists in one of the subtrees of found node, in which case the found node is the LCA
#include <iostream>
#include <bits/stdc++.h>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root == p || root == q){
            return root;
        }
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        if(left == NULL){
            return right;
        }
        if(right == NULL){
            return left;
        }
        return root;
    }
};