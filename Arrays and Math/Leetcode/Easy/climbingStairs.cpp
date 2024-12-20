//Leetcode Easy 70: no of ways to climb n stairs
//given an array of size n representing the no of stairs, return the no of ways to reach the top provided you can take either one or two steps at a time
//ex: 1) n=1: no of ways=1, 2) n=2, no of ways=2.
//on testing results for tes t cases with n =1,2,3 and 4, we notice a familiar pattern: the fibonacci series. This reduces the problem to return the (n+2)th order, provided you start with the third order, of the fibonacci series
class Solution {
public:
    int climbStairs(int n) {
       int temp=n;// good practice to not modify the given data and instead create a copy
       int a=0;//term 1
       int b=1;//term 2
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
