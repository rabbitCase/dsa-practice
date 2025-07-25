//Leetcode Easy 26
//Traverse the array and keep track of the first duplicate of an element(using replace pointer). This duplicate will be replaced by the first non duplicate encountered while traversing the array. Then increment replace so that other non duplicates can be switched. After full traversal, all non duplicates will be together and the rest of the array will be filled with duplicates.
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int replace = 1;
        for(int i= 1; i < nums.size(); i++){
            if(nums[i] != nums[i - 1]){
                nums[replace] = nums[i];
                replace++;
            }
        }
        return replace;
    }
};