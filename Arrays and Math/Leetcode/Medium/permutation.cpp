//Leetcode Medium 46
//Recursive backtracking where for every element in the array we dfs the entire array, appending all elements along the way. When we hit a base case(length of current solution = length of given array), we start popping elements so that we can explore other elements in the recursion tree. Every function call will have a for loop for traversal along the entire input array, therefore all paths are explored. We also check if the element has already been used in the current permutation cycle. The iterative loop only includes unused elements so as to avoid repetition or unwanted elements.
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> ans;
        vector<bool> used(nums.size(), false);
        backtrack(res, ans, nums, used);
        return res;
    }
    void backtrack(vector<vector<int>>& res, vector<int>& ans, vector<int>& nums, vector<bool>& used){
        if(ans.size() == nums.size()){
            res.push_back(ans);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(used[i]){
                continue;
            }
            used[i] = true;
            ans.push_back(nums[i]);
            backtrack(res, ans, nums, used);
            ans.pop_back();
            used[i] = false;
        }
    }
};