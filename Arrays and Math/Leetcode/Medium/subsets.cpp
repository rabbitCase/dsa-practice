//Leetcode Medium 76
//Add an element, recurse to add in all further elements, then remove this element to explore the recursion for the rest of the elements.
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> vec;
        backtrack(nums, res, vec, 0);
        return res;
    }
    void backtrack(vector<int>& nums, vector<vector<int>>& res, vector<int>& vec, int j){
        res.push_back(vec);
        for(int i = j; i < nums.size(); i++){
            vec.push_back(nums[i]);
            backtrack(nums, res, vec, i + 1);
            vec.pop_back();
        }
    }
};