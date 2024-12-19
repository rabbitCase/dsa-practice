//Leetcode Easy 121: Best time to buy and sell stock
/*Given an Array of prices, we have maximize our profit by buying and selling at the correct price
    Concept: Suppose you buy a product for $2 and eventually, the price of that product goes upto $6,
    now if you sell your product, you will recieve $6 which makes a total of $4 profit.
    We have to implement the same concept for the array of prices over time of a particular stock.
    Fundamentally, the problem asks us to find the maximum difference between two elements in an array*/
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
            buy=prices[i];//update buying price if it is lower than the current buying price
        }
        else{
        maxdiff=max(maxdiff,prices[i]-buy);
        }
        }
        return maxdiff;
    }
};
