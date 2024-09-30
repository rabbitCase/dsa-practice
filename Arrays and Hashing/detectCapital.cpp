//Leetcode Easy 520: Detect if the given string has used capitalization correctly
//Definition of right usage of capitals: Only the first letter is capital or all letters are capital or all letters are lowercase
#include <iostream>
#include <cctype>
using namespace std;
class Solution {
public:
    bool detectCapitalUse(string word) {
        bool capital;
        int n=word.length();
        if(!isupper(word[0])){//if first letter is lowercase then all further letters should be lowercase
                capital=true;
            for(int i=1;i<n;i++){
                if(isupper(word[i])){
                    capital=false;
                }
            }
        }
        else{
            if(isupper(word[1])){//if the next letter is uppercase then all further letters should be uppercase
                capital=true;
                for(int i=2;i<n;i++){
                    if(!isupper(word[i])){
                        capital=false;
                    }
                }
            } 
            else{
                capital=true;
                for(int i=2;i<n;i++){
                    if(isupper(word[i])){//else if the next letter is lowercase then all further letters should be lowercase
                        capital=false;
                    }
                }
            }   
        }
        return capital;
    }
};
