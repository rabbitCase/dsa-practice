//Leetcode Medium 2149: Reaarange Array
//Problem Statement: Given an array consisting of equal number of positive and negative numbers we have to return a vector satisfying:
//1) Vector should begin with a positive integer
//2) Positive  and negative integer should alternate
//3) The order of every interger with the same sign should be same as they were in the original vector
/*Concept: Create two vectors, s1 and s2, one which stores the positive integers and another one for the negative integers, as order is preserved, simply append one positive integer and then one negative integer to a new vector s3 recursively until s1 and s2 are empty*/
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector <int> s1;
        vector <int> s2;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=0){
                s1.push_back(nums[i]);
            }
            else if(nums[i]<0){
                s2.push_back(nums[i]);
            }
        }
        vector <int> s3;
        for(int i=0;i<s1.size();i++){//size of s1 and s2 are same 
            s3.push_back(s1[i]);
            s3.push_back(s2[i]);
        }
        return s3;
    }
};
//Test
int main(){
    Solution sol;
    vector <int> x={3,1,-2,-5,2,-4};
    vector<int> y=sol.rearrangeArray(x);
    for(int i=0;i<x.size();i++){
        cout<<y[i];
    }
}
