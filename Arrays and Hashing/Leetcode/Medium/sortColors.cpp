//Leetcode Medium 75: Sort colors
//Given an array containing only 0,1,2 (representing red,white,blue respectively), sort the array such that all the same colors are together and in the order red, white and blue. Ex: arr=[0,1,0,2,2,1,2,0], after sorting we get arr=[0,0,0,1,1,2,2,2].
/*Concept: First we have a hash map storing the frequency of the 0s, 1s and 2s. Then we iterate through the map 3 times (for 0 then 1 then 2) and append elements equal to the frequency the key(i.e 0/1/2) stores in the vector vec.
Ex: In the array [0,1,0,2,2,1,2,0] mpp will contain (0->3,1->2,2->3) therefore we append 0 three times then 1 two times and 2 three times in vec
The problem requires the function's return type to be void i.e it asks to modify the array/vector in-place, therefore we can change the original vector's value to match vec*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        unordered_map <int,int> mpp;
        vector <int> vec;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mpp[nums[i]]+=1;
        }
        for(auto x :mpp){//Iterator for the traversing the map
            if(x.first==0){//x.first is key
                for(int i=0;i<x.second;i++){//x.second is value
                    vec.push_back(0);//push_back() adds the element passed as the parameter to the vector vec.
                }
            }
        }
        for(auto x :mpp){
            if(x.first==1){
                for(int i=0;i<x.second;i++){
                    vec.push_back(1);
                }
            }
        }
        for(auto x :mpp){
            if(x.first==2){
                for(int i=0;i<x.second;i++){
                    vec.push_back(2);
                }
            }
        }
        for(int i=0;i<vec.size();i++){
            nums[i]=vec[i];
        }
    }
};
