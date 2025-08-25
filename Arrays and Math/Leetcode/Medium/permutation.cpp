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