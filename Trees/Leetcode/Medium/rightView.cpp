//Leetcode Medium 199
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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> res;
        vector<int> answer;
        if(!root){
            return answer;
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
        for(int i = 0; i < res.size(); i++){
            int size = res[i].size();
            answer.push_back(res[i][size - 1]);
        }
        return answer;
    }
};