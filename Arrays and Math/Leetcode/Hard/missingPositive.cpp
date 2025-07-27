//Leetcode Hard 41
//An array of size n can hold positive integers from [1,n], therefore if some other number replaces one of these, then the replaced number (or the missing number) must be between [1,n]. We do one pass to fill the hash table and another one to check the first unfilled position and return it. We do not consider elements < 1 or elements > n
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        vector<int> vec(nums.size() + 1, -1);
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < 0 || nums[i] > nums.size()){
                continue;
            }
            vec[nums[i]]++;
        }
    
        for(int i = 1; i < vec.size(); i++){
            if(vec[i] == -1){
                return i;
            }
        }
        return vec.size();
    }
};