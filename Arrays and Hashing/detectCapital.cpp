#include <iostream>
#include <cctype>
using namespace std;
class Solution {
public:
    bool detectCapitalUse(string word) {
        bool capital;
        int n=word.length();
        if(!isupper(word[0])){
                capital=true;
            for(int i=1;i<n;i++){
                if(isupper(word[i])){
                    capital=false;
                }
            }
        }
        else{
            if(isupper(word[1])){
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
                    if(isupper(word[i])){
                        capital=false;
                    }
                }
            }   
        }
        return capital;
    }
};
