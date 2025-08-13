#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size() + 1, -1);
        dp[0] = 0;
        dp[1] = nums[0];

        for(int i = 2; i <= nums.size(); i++){
            int robCurrent = nums[i - 1] + dp[i - 2];
            int robNext = dp[i - 1]; 

            dp[i] = max(robCurrent, robNext);
        }
        return dp[nums.size()];
    }
    // int dfs(vector<int>& nums, int n, vector<int> memo){
    //     if(n == 0){
    //         return 0;
    //     }
    //     if(n == 1){
    //         return nums[0];
    //     }
    //     if(memo[n] != -1){
    //         return memo[n];
    //     }
    //     int robCurrent = nums[n - 1] + dfs(nums, n -2, memo);
    //     int robNext = dfs(nums, n - 1, memo);

    //     return memo[n] = max(robCurrent, robNext);
    // }
};