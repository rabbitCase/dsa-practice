#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        std::unordered_map<char,int> set;
        for(auto x:s){
            set[x]++;
        }
        for(auto x:t){
            set[x]--;
        }
        for(int i=0;i<set.size();i++){
            if(set[i]!=0)
            return false;
        }
        return true;
    }
};
