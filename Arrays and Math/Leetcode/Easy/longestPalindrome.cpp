//Leetcode Easy 409
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mpp;
        int length=0;
        bool oddFound= false;
        for(auto x : s){
            mpp[x]++;
        }
        for(auto y : mpp){
            
            if(y.second % 2 ==0){
                length+= y.second;
            }
            else{
                length+= y.second -1;
                if(!oddFound){
                    length +=1;
                    oddFound=true;
                }
            }
        }
        return length;
    }
};