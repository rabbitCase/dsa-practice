//Leetcode Medium 98: Check whether a BST is valid or not
//A valid BST has left child smaller than the parent and the right child greater than the parent
//The approach is to recursively check if the currrent node lies within it's allowed range. The range for the root node is INT_MIN to INT_MAX. For the left child, the minimum value can be anything between [INT_MIN, root->val), similarily, the right child can take the values (root->val, INT_MAX] (note that root->val is not included for either children). Therefore, we update the min and max values for every function call. As the given function only takes one parameter, we have to use a private helper function.

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
    bool isValidBST(TreeNode* root){
        return isValid(root,LONG_MIN, LONG_MAX);//Used LONG_MIN/MAX instead of INT due to the nature of some testcases
    }
private:
    bool isValid(TreeNode* root, long min, long max) {
        if(!root){//Encountered a null node
            return true;//A null node is a valid BST
        }
        if(root->val >= max || root->val <= min){
            return false;
        }
        return isValid(root->left, min, root->val) && isValid(root->right, root->val, max); //for root->left, max value is now changed and for root->right, the min value is changed, this change happens for every recursive call
    }
};
