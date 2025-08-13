//Leetcode Medium 198
//We can either rob the current house in which case we add the amount  we get from the current (nth) house and then solve the same problem recursively for the (n - 2)th house as adjacent houses cannot be robbed. If we choose to not rob the current house, we don't the add the amount from the current house and instead solve the same problem recursively for the adjacent (n - 1)th house.
//return the max value we get by deciding to rob or not rob every house

//Using a dfs approach with a memo table exceeds memory limit on leetcode, hence we use a bottom up dp array to compute the max value we get by either robbing the current house or robbing the next valid house. Since only the last two indices of the array are being used, space can further be optimised by only using two variables instead of the array and updating them to the next two indices
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