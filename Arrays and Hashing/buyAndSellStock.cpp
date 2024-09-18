//Leetcode Easy 121: Best time to buy and sell stock
#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i,maxdiff=0,buy=prices[0];
        for(i=1;i<prices.size();i++){
        if(prices[i]<buy){
            buy=prices[i];
        }
        else{
        maxdiff=max(maxdiff,prices[i]-buy);
        }
        }
        return maxdiff;
    }
};
