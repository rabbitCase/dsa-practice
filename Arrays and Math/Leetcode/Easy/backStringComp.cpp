//Leetcode Easy 844
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        vector<char> vec1 ,vec2;
        for(auto x : s){
            vec1.push_back(x);
            if(x == '#'){
                vec1.pop_back();
                if(!vec1.empty()){
                    vec1.pop_back();
                }
                
            }
        }

        for(auto x : t){
            vec2.push_back(x);
            if(x == '#'){
                vec2.pop_back();
                if(!vec2.empty()){
                    vec2.pop_back();
                }
                
            }
        }
        return vec1 == vec2;
    }
};
