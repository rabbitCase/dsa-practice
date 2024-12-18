//Leetcode Medium 53: Maximum Subarray
//Given an array, we have to find the subarray with the maximum sum. Eg: [1,2,-1,3], maximum subarray: [2,-1,3] 
//Concept: We use kadane's algorithm, the jist of which is to traverse through the array and keep on adding the elements to a sum variable only if the current element to be added does not decrease the previous sum value.
//There are multiple other approaches like recursion, Divide and Conquer, Memoization etc. all of which will be updated as I learn more.
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int sum=0,best=INT_MIN;//best should be INT_MIN (and not 0) to handle cases where the array contains only negative integers
        for(int i=0;i<n;i++){
            sum=max(nums[i],(sum+nums[i]));//sum only updates if (sum+nums[i]) > nums[i], thereby ensuring sum only updates if the added element does not  
            best=max(best,sum);            //decrease it's value
        }
        return best;
    }
};
//Better way to understand the algorithm
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int n=nums.size();
//         int sum=0,best=INT_MIN;
//         for(int i=0;i<n;i++){
//             sum+=nums[i];
//             if(sum<nums[i]){
//                 sum=nums[i];
//             }
//             best=max(sum,best);
//         }
//         return best;
//     }
// };
