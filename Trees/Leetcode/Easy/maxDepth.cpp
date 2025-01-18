//Leetcode Easy 104: Return maximum depth of a Binary tree
//We use recursion to traverse the tree with two integer pointers left and right. We calculate the max depth of each subtree + 1, finally, after the function stack is fully executed, the max(left,right) gives us the max depth.
#include <iostream>

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
    int maxDepth(TreeNode* root) {
        if(!root){
            return 0;
        }
        int left=maxDepth(root->left);
        int right=maxDepth(root->right);

        return std::max(left,right) +1;
    }
};
