//Leetcode Easy 169
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return nums[(nums.size())/2];
    }
};
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         unordered_map <int,int> hash(nums.size());
//         int best=0;
//         int n=nums.size();
//         for(int i=0;i<n;i++){
//             hash[nums[i]]++; 
//         }
//         n/=2;
//         for(auto x: hash){
//             if(x.second > n){
//                 return x.first;
//             }
//         }
//         return best;
//     }
// };
int main(){
    Solution sol;
    vector <int> x={2,2,1,1,1,2,2};
    cout<< sol.majorityElement(x);
}