#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        int arr[nums.size()];
        int best=-99999;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
    }
};
//Need to learn priortity queue