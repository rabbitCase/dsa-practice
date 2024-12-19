//Leetcode Easy 263: An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5
class Solution {
public:
    bool isUgly(int n) {
        if(n==1){
            return true;
        }
        if(n<1){
            return false;
        }
        while(n%2==0){
           n/=2;}
        while(n%3==0){
            n/=3;
        }
        while(n%5==0){
            n/=5;
        }
        if(n>1){
            return false;
        }
        return true;
    }
};
