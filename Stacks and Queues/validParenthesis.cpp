//Leetcode Easy 20: Given a string containg only '()', '{}', or '[]' check if the parenthesis placement is valid.
/*Concept: for '(', '{' and '[', push it into our stack, now if we encouter a closing bracket, the top of the stack must contain its respective opening bracket, therefore if the string is valid, the stack should be empty after full string traversal which means top==-1*/
#include <iostream>
#include <bits/stdc++.h>
#include <string.h>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        char stack[50000];//max string length given
        int top=-1;
        for(char i:s){
            if(i=='('|| i=='{'||i=='['){
                stack[++top]=i;//push opening braces
            }
            else{
                if(top==-1) return false;//in the case where there are no opening braces
                char temp=stack[top--];//pop the topmost element
                if(i==')'&&temp!='('||
                   i=='}' && temp!='{'||i==']'&&temp!='['){
                    return false;
                   }
            }
        }
        return top==-1;//stack should be empty if string is valid
    }
};
