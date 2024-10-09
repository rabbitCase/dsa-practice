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
                if(mpp.count(tolower(word[i])) && !s.count(word[i])){
                    count++;
                }
                s[word[i]]=i;
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