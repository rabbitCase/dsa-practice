//Leetcode Easy 226: Invert a binary tree
//Concept: We have to invert a binary tree i.e interchange nodes such that the resulting binary tree is the mirror image of the first. This can be done recursively by taking the root node and swapping it's left and right child and then call the function again but this time passing the swapped left and right node as parameters until all leaf nodes become null.
//Recursive approach
#include <iostream>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
 
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root){
            return root;
        }
        TreeNode *temp=root->left;
        root->left=root->right;
        root->right=temp;

        invertTree(root->left);//The swapped node becomes the  new root
        invertTree(root->right);
        return root;
    }
};
