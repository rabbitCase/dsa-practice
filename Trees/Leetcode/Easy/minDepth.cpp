//Leetcode Easy 111
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
    int minDepth(TreeNode* root) {
        return dfs(root);
    }
    int dfs(TreeNode *root){
        if(!root){
            return 0;
        }

        if(!root->right){
            return dfs(root->left) + 1;
        }

        if(!root->left){
            return dfs(root->right) + 1;
        }

        return min(dfs(root->left), dfs(root->right)) + 1;
    }
};