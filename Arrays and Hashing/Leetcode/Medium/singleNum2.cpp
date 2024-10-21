//Leetcode Medium 137
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
            ans=x.second;
            break;
            }
        }
        return ans;
    }
};