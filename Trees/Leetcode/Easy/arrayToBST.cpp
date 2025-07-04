//Leetcode Easy 108
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return solve(nums, 0, nums.size() - 1);
    }

    TreeNode* solve(vector<int> nums, int left, int right){
        if(left > right){
            return nullptr;
        }

        int mid = left + (right - left)/2;
        TreeNode *head = new TreeNode(nums[mid]);

        head -> left = solve(nums, left, mid - 1);
        head -> right = solve(nums, mid + 1, right);

      return head;
    }
};