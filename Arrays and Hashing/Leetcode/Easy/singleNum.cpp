//Leetcode Easy 136: Find the number which appears once in the array
/*The Question asks for linear time complexity and constant space. The common approach of using hash map (which is used here) solves the former but fails at the latter. The concept of bit manipulation is to be studied for fulfilling both the problem conditions. The problem may be updated in the future when I have a better grasp of bit manipulation*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map <int,int>  mpp; int ans;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        for(auto x:mpp){
            if(x.second==1){
            ans=x.first;
            break;
            }
        }
        return ans;
    }
};
