//Leetcode Easy 70: no of ways to climb n stairs
//given an array of size n representing the no of stairs, return the no of ways to reach the top provided you can take either one or two steps at a time
class Solution {
public:
    int climbStairs(int n) {
       int temp=n;
       int a=0;
       int b=1;
       int sum;
       while(temp>0){
        sum=a+b;
        a=b;
        b=sum;
        temp--;
       }
       return sum;
    }
};
