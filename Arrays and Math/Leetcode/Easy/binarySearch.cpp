//Leetcode Easy 704: Perform Binary Search on a sorted (ascending) array
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
