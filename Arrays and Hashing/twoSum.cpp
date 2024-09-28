#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int,int> mpp;
    int complement;
    for(int i=0;i<nums.size();i++){
        complement=target-nums[i];
        if(mpp.count(complement)){//.count() returns 1 if index exists
             return {mpp[complement],i};
        }
        mpp[nums[i]]=i;//Add index to the map later because
    }                  //the newly added element can be equal
    return {};         //to the complement in the same loop cycle
    }                  //which means i will be equal to mpp[complement]
};                     //ex: {3,3} and k=6, here when i=0 mpp has
                       //3->0, the 'if' condition satisfies and we get
                       //[0,0] when it should be [0,1], so first check
                       //if condition, and then add to the map
                       //so that comp is checked in the next cycle