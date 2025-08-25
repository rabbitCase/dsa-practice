#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    char repeatedCharacter(string s) {
        vector<int> res(123, 0);
        for(auto x : s){
            if(++res[x - 'a'] > 1){
                return x;
            }
        }
        return 'a';
    }
};