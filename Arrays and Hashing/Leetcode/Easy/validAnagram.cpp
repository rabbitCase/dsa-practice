//Leetcode Easy 242: Return true if t is an anagram of s
//Concept: An anagram is word which can be formed by reaaranging some other word, usually using every letter only once
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        std::unordered_map<char,int> set;
        for(auto x:s){
            set[x]++;//push all characters of s into map
        }
        for(auto x:t){
            set[x]--;//if t is an anagram, after removing all letters of t from the map, the map should contain 0 characters
        }
        for(int i=0;i<set.size();i++){
            if(set[i]!=0)
            return false;
        }
        return true;
    }
};
