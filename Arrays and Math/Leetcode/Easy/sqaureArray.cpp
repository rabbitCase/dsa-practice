//Leetcode easy 977
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> vec(nums.size(), 0);
        int left = 0;
        int right =  nums.size() - 1;
        int index = right;
        while(left <= right){
            int temp = abs(nums[left]) > abs(nums[right]) ? nums[left] : nums[right];
            vec[index] = temp*temp;
            index--;
            abs(nums[left]) > abs(nums[right]) ? left++ : right--;
        }
        
        return vec;
    }
};