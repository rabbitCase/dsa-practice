//Leetcode Easy 383: Ransom Note
//Given two strings ransomNote and magazine, determine wether ransomNote can be contructed using the characters in magazine, each magazine character can only be used once

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
