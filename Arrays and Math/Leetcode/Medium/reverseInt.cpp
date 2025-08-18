//Leetcode Medium 7
//Follows the common logic of multiplying answer by 10 and adding the last digit of the number to be reversed
//IMT_MAX (32 bit) is 2,147,483,647. Before that last digit is appended, if the reversed number is 2,147,483,64 it will overflow when a value greater than 7 is added after being multiplied by 10. Also if the reversed number is greater than 2,147,483,64 it will again overflow when multiplied by 10. Similar logic for underflow.
#include <iostream>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while(x != 0){
            int temp = x % 10;
            if(res > INT_MAX / 10 || (res == INT_MAX / 10 && temp > 7)){
                return 0;
            }
            if(res < INT_MIN / 10 || (res == INT_MIN / 10 && temp < -8)){
                return 0;
            }
            res *= 10;
            res += temp;
            x /= 10;
        }
        return res;
    }
};