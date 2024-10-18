//Leetcode Medium 75
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        unordered_map <int,int> mpp;
        vector <int> vec;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mpp[nums[i]]+=1;
        }
        for(auto x :mpp){
            if(x.first==0){
                for(int i=0;i<x.second;i++){
                    vec.push_back(0);
                }
            }
        }
        for(auto x :mpp){
            if(x.first==1){
                for(int i=0;i<x.second;i++){
                    vec.push_back(1);
                }
            }
        }
        for(auto x :mpp){
            if(x.first==2){
                for(int i=0;i<x.second;i++){
                    vec.push_back(2);
                }
            }
        }
        for(int i=0;i<vec.size();i++){
            nums[i]=vec[i];
        }
    }
};