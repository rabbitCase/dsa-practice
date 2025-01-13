//Leetcode Medium 15: 3 sum
//find all triplets in an array which add upto 0
//Concept: We first sort the array, then we can use the two pointer approach where we fix one index of the array and then initialise two pointers, one ahead of the fixed element and one at the end. If the elements at these 3 indices add upto 0, we push the triplet into the vector, if not, we move the pointers inward. We do this for every index. Note that moving the pointers inwards is working only because the array is sorted. It is also necesssary to avoid duplicates, so, we don't include an index to check if the element at that index was same previously.
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       vector<vector<int>> vec;
       int size=nums.size();
       sort(nums.begin(),nums.end());
       for(int i=0;i<size;i++){
        if (i>0 && nums[i] == nums[i - 1]) //avoid checking for duplicates
        continue;
        int j=i+1;
        int k=size-1;
        while(j<k){
            int sum=nums[i]+nums[j]+nums[k];
            if(sum==0){
                vec.push_back({nums[i],nums[j],nums[k]});
                j++;
                k--;
                while(j<k && nums[j]==nums[j-1]){//for the current fixed index, we do not include the left pointer if the element it is pointing to was the same    
                    j++;                         //after moving inward
                }
                while(j<k && nums[k]==nums[k+1]){
                    k--;
                }
            }
            else if(sum<0){
                j++;
            }
            else{
                k--;
            }
        }
       }
       return vec;
    }
};
