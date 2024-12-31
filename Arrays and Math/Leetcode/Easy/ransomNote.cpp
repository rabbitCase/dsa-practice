//Leetcode Easy 383: Ransom Note
//Given two strings ransomNote and magazine, determine wether ransomNote can be contructed using the characters in magazine, each magazine character can only be used once
//Method 1: create two unordered maps to store the frequency of characters in magazine and ransomNote and then compare the frequency parameter of both the strings. If a character in ransomNote has a higher frequency as compared to magazine, then construction is not possible
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
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> magazinefreq; 
        for (auto x : magazine) { 
            magazinefreq[x]++; 
        } 
            
        for (auto x : ransomNote) { 
            if (magazinefreq[x] <= 0) { 
                return false; 
            }
            magazinefreq[x]--; 
        } 
        return true;
    }
};

