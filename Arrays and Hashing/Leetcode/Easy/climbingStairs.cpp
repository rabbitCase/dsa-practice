//Leetcode Easy 70
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