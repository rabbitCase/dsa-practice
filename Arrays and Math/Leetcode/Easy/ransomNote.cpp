//Leetcode Easy 383
#include <iostream>
#include <bits/stdc++.h>
class Solution {
public:
    bool canConstruct(std::string ransomNote, std::string magazine) {
        std::unordered_map <char,int> ransomfreq;
        std::unordered_map <char,int> magazinefreq;
        for(auto x : magazine){
            magazinefreq[x]++;
        }
        for(auto x: ransomNote){
            ransomfreq[x]++;
        }
        for(auto x : ransomNote){
            if(ransomfreq[x] > magazinefreq[x]){
                return false;
            }
        }
        return true;
    }
};