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