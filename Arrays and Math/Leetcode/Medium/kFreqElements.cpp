#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        vector<int> vec;
        vector<int> result;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        for(auto x : mpp){
            vec.push_back(x.second);
        }
        sort(vec.begin(), vec.end(), greater<int>());
        int n = vec.size();
        int iterable = n - k;
        while(iterable--){
            vec.pop_back();
        }
        for(auto y : vec){
            for(auto x : mpp){
                if(x.second == y){
                    result.push_back(x.first);
                    mpp.erase(x.first);
                    break;
                }
            }
        }
        return result;
    }
};