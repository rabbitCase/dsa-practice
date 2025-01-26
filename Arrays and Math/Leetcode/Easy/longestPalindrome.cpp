//Leetcode Easy 409: find the length of the longest palindrome that can be formed with the given string
//Concept: A palindrome can be formed if a char occurs with even frequency, for example: "aabbcc" can be used to form the palindrome: "abccba". There can only be one odd frequency character in our palindrome which will be placed in the middle (ex: "aaabbccde" has "abcacba" or "abcdcba" or "abcecba"as palindrome). Therefore, when we encounter an odd frequency char, we add it to the length only once, after that, on further odd frequency encounters, we only add the even part (as one odd character has already been added). 
//We use a character-integer paired map to store the frequency of every character in the string. A bool is initialised to false to keep track if an odd frequency was added to the length, once we add an odd length (say size 7), we know that the even part (of size 6) will be in the two extreme sides of the palindrome distributed evenly, and the left over character will be placed in the middle. After this, we can only take the even part from odd lengths, therefore, we set oddFound to true and if we encounter a chracter with odd frequency again, we only take the even part out of it and distribute it evenly to form the palindrome.
//Ex: "aaabbbccd", frequency map looks like a->3, b->3, c->2, d->1
//After we have added the length 3 from a, we can only add 2 from b and 2 from c, which makes the total length 3+2+2= 7
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
            //iterator->first and interator->second return key and value pairs respectively from the unordered map
            if(y.second % 2 ==0){
                length+= y.second;
            }
            else{
                length+= y.second -1;//only take the even part (if n is odd, n-1 is even)
                if(!oddFound){
                    length +=1;
                    oddFound=true;//no more odd frequency characters can be taken
                }
            }
        }
        return length;
    }
};
