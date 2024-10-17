//Leetcode Medium 152: Maximum Product Subarray
/*Concept: We have to find a subarray that has the largest product, and return the product. Here we can apply 2 loops, find every subarray and compare their products, but a better way to do this is apply the same concept we learned while calculating maximum subarray sum that is Kadane's algorithm. We modify the concept a little bit and use the algorithm for multiplication instead of addition. So we traverse through the array from both ends and store the subsequent product while comparing the maximum product obtained so far and store it in 'best'. At any point, if product becomes 0, then further product would just yield zero therefore in that case we set product to 1. The reason we traverse from both ends is that if we have a negative integer in the begining of the array then further products will all become negative, therefore it is necessary to traverse from the other end too.*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int product=1,best=-999;
        for(int i=0;i<nums.size();i++){
            product*=nums[i];
            best=max(best,product);
            if(product==0)
            product =1;//change product to 1 only after best has been assigned, otherwise best could be assigned 1 instead of 0
        }
        product=1;//resert product for right to left traversal but don't reset best
        for(int i=nums.size()-1;i>=0;i--){
            product*=nums[i];
            best=max(best,product);
            if(product==0)
            product=1;
        }
        return best;
    }
};
