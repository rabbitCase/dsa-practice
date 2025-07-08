//Leetcode Easy 110
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
    bool isBalanced(TreeNode* root) {
        if(!root){
            return true;
        }

        int left = height(root -> left);
        int right = height(root -> right);

        bool isLeftBalanced = isBalanced(root -> left);
        bool isRightBalanced = isBalanced(root -> right);
        return std::abs(left - right) <= 1 && isLeftBalanced && isRightBalanced;
    }

    int height(TreeNode *root){
        if(!root){
            return 0;
        }
        
        return (1 + max(height(root->left), height(root->right)));
    }
};