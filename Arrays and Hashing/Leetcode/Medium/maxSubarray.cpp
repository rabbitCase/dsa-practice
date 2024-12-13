//Leetcode Medium 53
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int sum=0,best=INT_MIN;
        for(int i=0;i<n;i++){
            sum=max(nums[i],(sum+nums[i]));
            best=max(best,sum);
        }
        return best;
    }
};