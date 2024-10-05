//Leetcode Easy 1: Given an array of integers and a target k, we have to return indices two indices i,j such that a[i]+a[j]=k
//Concept: Traverse through the array and for every element a, check if k-a exists in the traversed array, if it does, then return the index of that element and the current element. We can use an unordered map to pair the traversed element with it's index.
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
        complement=target-nums[i];//complement is k-a
        if(mpp.count(complement)){//.count() returns 1 if index exists
             return {mpp[complement],i};
        }
        mpp[nums[i]]=i;//Add index to the map later because
    }                  //the newly added element can be equal
    return {};         //to the complement in the same loop cycle
    }                  //which means i will be equal to mpp[complement]
};                     //ex: nums<int>= {3,3} and k=6, here when i=0 mpp has
                       //3->0, the 'if' condition satisfies and function returns
                       //[0,0] when it should be [0,1], so first check
                       //if condition, and then add to the map
                       //so that comp is checked in the next cycle
