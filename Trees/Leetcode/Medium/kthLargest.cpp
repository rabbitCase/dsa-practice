//Leetcode Medium 215
//Utilizing a priority queue to store all elements and subsequently keep popping (k - 1) times until we find the kth largest element in the vector
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int size = nums.size();
        priority_queue<int> pq;
        for(auto x : nums){
            pq.push(x);
        }
        while(k > 1){
            pq.pop();
            k--;
        }
        return pq.top();
    }
};