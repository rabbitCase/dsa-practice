//Leetcode Medium 2149
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
        for(int i=0;i<max(s1.size(),s2.size());i++){
            s3.push_back(s1[i]);
            s3.push_back(s2[i]);
        }
        return s3;
    }
};
int main(){
    Solution sol;
    vector <int> x={3,1,-2,-5,2,-4};
    vector<int> y=sol.rearrangeArray(x);
    for(int i=0;i<x.size();i++){
        cout<<y[i];
    }
}