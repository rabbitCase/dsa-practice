//Leetcode Medium 152
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int product=1,best=-999;
        for(int i=0;i<nums.size();i++){
            product*=nums[i];
            best=max(best,product);
            if(product==0)
            product =1;
        }
        product=1;
        for(int i=nums.size()-1;i>=0;i--){
            product*=nums[i];
            best=max(best,product);
            if(product==0)
            product=1;
        }
        return best;
    }
};