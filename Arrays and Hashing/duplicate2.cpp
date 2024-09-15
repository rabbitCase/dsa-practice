//Leetcode Easy 219: return true if nums[i] == nums[j] and abs(i - j) <= k.
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map <int,int> mpp;
        int i;
        for(i=0;i<nums.size();i++){
            if(mpp.count(nums[i])>=1){//.count() returns frequency of nums[i]
                if(i-mpp[nums[i]]<=k){//important to check condition first and only then update value of mpp
                    return true;
                }
            }
            mpp[nums[i]]=i;
        }
        return false;
    }
};
int main(){
    Solution hello;
    int k=2;
    vector <int> nums={1,2,3,1,2,3};
    cout << hello.containsNearbyDuplicate(nums,k);
}
