//Leetcode Easy 704: Perform Binary Search on a sorted (ascending) array
//Time complexity of a binary search is O(log2n) or in other words, the data size to search is being divided by two for every search iteration
//Performing a binary search is simple, although the primary condition we require is that the data should be sorted in ascending or descending order
//
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int high=nums.size()-1;
        int low=0;
        int mid;
        while(low<=high){
            mid=(high+low)/2;
            if(nums[mid]<target)
            low=mid+1;

            else if(nums[mid]>target)
            high=mid-1;

            else 
            return mid;

        }
        return -1;//default if element not found in array
    }
};

int main(){
    vector<int> num={-1,2,3,4,5};
    Solution sol;
    cout<< sol.search(num,4);
}
