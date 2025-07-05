//Leetcode Easy 572
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root && !subRoot){
            return true;
        }
        if(!root || !subRoot){
            return false;
        }
        if(same(root, subRoot)){
            return true;
        }
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
    bool same(TreeNode *p, TreeNode *q){
        if(!p && !q){
            return true;
        }
        if(!p || !q){
            return false;
        }
        return p->val == q->val && same(p->left, q->left) && same(p->right, q->right);
    }
};