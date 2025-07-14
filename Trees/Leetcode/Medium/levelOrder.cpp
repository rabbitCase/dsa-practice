//Leetcode Medium 102
//push the root to the queue first, then add the children to the queue if they exist, then iterate through the queue and check if subsequent children exist for every node. Finally pop the front of the queue after checking. Do this while the queue is not empty
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> res;
        if(!root){
            return res;
        }
        q.push(root);
        while(!q.empty()){
            vector<int> vec;
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode* front = q.front();
                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
                q.pop();
                vec.push_back(front->val);
            }
            res.push_back(vec);
        }
        return res;
    }

};