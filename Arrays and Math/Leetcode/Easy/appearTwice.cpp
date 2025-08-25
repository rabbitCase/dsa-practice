//Leetcoed Easy 2351
//current char is used as index in an array. The first index to reach value > 1 is the first letter to appear twice
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    char repeatedCharacter(string s) {
        vector<int> res(26, 0);
        for(auto x : s){
            if(++res[x - 'a'] > 1){
                return x;
            }
        }
        return 'a';
    }
};