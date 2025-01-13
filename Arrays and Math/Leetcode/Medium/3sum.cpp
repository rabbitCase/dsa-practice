//Leetcode Medium 15: 3 sum
//find all triplets in an array which add upto 0
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
        if (i>0 && nums[i] == nums[i - 1]) 
        continue;
        int j=i+1;
        int k=size-1;
        while(j<k){
            int sum=nums[i]+nums[j]+nums[k];
            if(sum==0){
                vec.push_back({nums[i],nums[j],nums[k]});
                j++;
                k--;
                while(j<k && nums[j]==nums[j-1]){
                    j++;
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
