//Leetcode Easy 409: find the length of the longest palindrome that can be formed with the given string
//Concept: A palindrome can be formed if a char occurs with even frequency, for example: "aabbcc" can be used to form the palindrome: "abccba". There can only be one odd frequency character in our palindrome which will be placed in the middle (ex: "aabbccde" has "abcdcba" or "abcecba"as palindrome). Therefore, when we encounter an odd frequency char, we add it to the length only once, after that, on further odd frequency encounters, we only add the even part (as one odd character has already been added). 
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
