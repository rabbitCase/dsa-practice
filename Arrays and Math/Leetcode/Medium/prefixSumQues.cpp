//Number of subarrays with sum K

/* In a subarray with n elements prefix sum is iterating through 
the array and storing the subsequent sum s. Now, to check the sum k 
exists, we have to check if s-k exists in the hashmap we 
will create, if it does exist we increase our count to the number of
times it exists. This is because if k exists then s-k must exist to
make the total sum to be s or s-k+k=0. 
Also setting the freq[0]=1 is important.
example: arr= 1,2,3,-3,1,1
         let s=6 (1+2+3-3+1+1) and k=3
         s-k=3,so we have to search for freq. of 3.
         s was 3 at points (1+2) and (1+2+3-3), so 
         hash[s-k]=hash[3]=2 therefore, count+=2 */
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
    int i,count=0,sum=0; unordered_map<int,int> mpp;
    mpp[0]=1;//very important
    for(i=0;i<nums.size();i++){
        sum+=nums[i];
        count+=mpp[sum-k];
        mpp[sum]++;
   }
   return count;
}
};
