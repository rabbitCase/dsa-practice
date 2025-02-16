//Leetcode Easy 100: Same tree
//We have to check whether the the given heads of two trees and equal in structure and values.
//Concept: We check the current value of p and q, if they are equal, we recursively check for equality for the left and right values of both p and q
//Note: The trees are equal if both roots are null
#include <iostream>
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q){
            return true;
        }
        if(!p || !q){
            return false;
        }
        
        return (p->val == q->val && isSameTree(p->left,q->left) && isSameTree(p->right,q->right));

    }
};
