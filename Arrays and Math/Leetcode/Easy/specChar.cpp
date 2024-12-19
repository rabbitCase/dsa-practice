//Leetcode Easy 3120: Count the number of special characters in the string
/*Concept: A special character is character that appears in both uppercase and lowercase in the same string. Store the lowercase letters in an unordered map first. Then traverse through the string again. If we encounter an uppercase letter, check if it's lowercase is present in the array, if so, increment count */
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map <char,int> mpp;
        unordered_map <char,int> s;
        int count=0;
        for(int i=0;i<word.length();i++){
            if(islower(word[i])){
                mpp[word[i]]=i;
            }
        }
        for(int i=0;i<word.length();i++){
            if(isupper(word[i])){
                if(mpp.count(tolower(word[i])) && !s.count(word[i])){//If we have already checked for the letter previously, then it will be present in s and 
                                                                      //therefore in that case we don't increment count
                    count++;
                }
                s[word[i]]=i;//first check if the letter has been checked for and only then add the checked letter to s
            }
        }
        return count;
    }
};

// Better method: Use set as it stores unique characters only(no duplicates)
// class Solution {
// public:
//     int numberOfSpecialChars(string word) {
//         int count=0;
//         unordered_set<char>s;
//         for(int i=0;i<word.length();i++){
//             s.insert(word[i]);
//         }
//         for(char c:s){
//             if(s.find(c+32)!=s.end())count++;
//         }
//         return count;
//     }
// };
