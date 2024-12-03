//Leetcode Easy 125: Valid Palindrome
//Check if the given string is a  palindrome. Ignore all non alphanumeric characters and convet uppercase characters to lowercase
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    char tolower(char ch){
        if(ch >= 'A' && ch <= 'Z'){
            return ch - 'A' + 'a';
        }
        return ch;
    }

    bool isPalindrome(string s) {
        int i,j;
        i=0;
        j=s.length()-1;
        
        while(i<j){
            while(i<j && !isalnum(s[i])){//important to add an i<j condition as i can get bigger than j inside the nested while
                i++;
            }
            while(i<j && !isalnum(s[j])){
                j--;
            }
            if(tolower(s[i]) != tolower(s[j])){
                return false;
            }
            else{
                i++; j--;
            }
        }
        return true;
    }
};
