//Leetcode Easy 704: Perform Binary Search on a sorted (ascending) array
//Time complexity of a binary search is O(log2n) or in other words, the data size to search is being divided by two for every search iteration
//Performing a binary search is simple, although the primary condition we require is that the data should be sorted in ascending or descending order
//Example for the case of numbers: search 11 in the array a=[1,3,5,7,9,11,13]. We have high pointer pointing to the end index and low pointer pointing to the first index while mid pointer points to the middle index between the range [low,high]. If element at mid index is less than the element to be searched for (target), then that means the target is in the right half of the array, therefore, mid becomes the new low and high remaing the same. We recalculate mid with the new low and continue the comparison and update low or high depending on the value of mid. We do this till low <= high. 
// For the example high, low and mid update as follows:
//Iteration 1: low=0 , high=6, mid=(6+0)/2 = 3, a[mid]=7 (which is less than target 11)
//Iteration 2: low=3, high=6, mid=4, a[mid] = 9 < 11
//Iteration 3: low=4, high=6, mid=5, a[mid] = 11 == 11 (target)
//return mid = 5 where the element was found
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
