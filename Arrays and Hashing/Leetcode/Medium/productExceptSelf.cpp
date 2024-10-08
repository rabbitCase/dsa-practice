#include <iostream>
#include <bits/stdc++.h>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector <int> result(n),postfix(n+1),prefix(n+1);
        int i;
        /*Create postfix array and prefix array
        then result[i] is prefix[i-1]*postfix[i+1]
        We can shift prefix array by one unit to the right
        and Post fix array to the left by adding extra 1 to the left
        and right respectively so that we can write
        result[i]=prefix[i]+postfix[i], this will prevent
        out of bounds error when, for ex, i=0
        example: [1,2,3,4]
        prefix: [(1),1,2,6,24]
        postfix: [24,24,12,4,(1)]
        result: [24,12,8,6]*/
        prefix[0]=1;
        for(i=1;i<=n;i++){
            prefix[i]=prefix[i-1]*nums[i-1];
        }
        postfix[n]=1;
        for(i=n-1;i>=0;i--){
            postfix[i]=postfix[i+1]*nums[i];
        }
        for(i=0;i<n;i++){
            result[i]=prefix[i]*postfix[i+1];
        }
        return result;
    }//Can be optimised further
};
int main(){
    Solution sol;
    vector<int> nums={1,2,3,4};
    for(int i=0;i<nums.size();i++){
        sol.productExceptSelf(nums);
    }
}