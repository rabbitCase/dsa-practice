//Leetcode Easy 543
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
     int result  = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        heightAtEachNode(root);
        return result;
    }
    int heightAtEachNode(TreeNode* head){
        if(!head){
            return 0;
        }
        int leftLength = heightAtEachNode(head -> left);
        int rightLength = heightAtEachNode(head -> right);

        result = max(result, leftLength + rightLength);
        return (1 + max(leftLength , rightLength));
    }
};