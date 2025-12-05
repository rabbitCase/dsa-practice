//Leetcode medium 55
//calculate the maximum distance we can jump from each index taking into account the distance we have covered so far as well. If max jump distance < next index, we are stuck
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