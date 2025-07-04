//Leetcode Easy 268
#include <iostream>
#include <bits/stdc++.h>
class Solution {
public:
    int missingNumber(std::vector<int>& nums) {
        int size = nums.size();
        int sum = size*(size+1)/2;
        for(int i = 0; i < size; i++){
            sum -= nums[i];
        }
        return sum;
    }
};