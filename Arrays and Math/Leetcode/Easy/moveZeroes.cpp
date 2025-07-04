//Leetcode Easy 283
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size = nums.size();
        int replacingIndex = 0;
        for(int i = 0; i < size; i++){
            if(nums[i] != 0){
                nums[replacingIndex++] = nums[i];
            }
        }
        while(replacingIndex < size){
            nums[replacingIndex++] = 0;
        }
    }
};