//Leetcode medium 55
#include <iostream>
#include <vector>
class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        int maxi = 0;
        int cur = 0;

        if(nums[0] == 0 && nums.size() != 1){
            return false;
        }

        for(int i = 0; i < nums.size(); i++){
            if(i > maxi){
                return false;
            }
            maxi = std::max(maxi, i + nums[i]);
        }
        return true;
    }
};