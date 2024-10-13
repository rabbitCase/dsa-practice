//Leetcode Easy 169 : Find the majority element in a given array. Majority element is the element which appears more than n/2 times where n is the size of the array.

/*Concept: We can always use a hash map to store the frequency of every element in the array and then compare the frequency with n/2 to find the majority element, but there is a simple concept than can also be used: when we sort the array, the majority element must be present in the middle of the array, as the element occupies more than half the size of the array. So, we can simply sort our array (a vector in this case) and return the element at index n/2*/
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

//We cannot use a simple array for hashing as we can be given negative integers, so the array will not be able to map the frequency of those numbers
//Using unordered map (element mapped to its frequency)
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

//Test 
int main(){
    Solution sol;
    vector <int> x={2,2,1,1,1,2,2};//Majority element is 2 as it appears more than 3 (7/2) times
    cout<< sol.majorityElement(x);
}
