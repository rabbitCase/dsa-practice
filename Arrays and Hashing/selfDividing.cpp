//Leetcode Easy 728: Return all self dividing numbers in the range given
//Self dividing numbers are divisilble by every digit they contain
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector <int> result;
        int temp,i,num;
        for(i=left;i<=right;i++){
            bool check=true;
            num=i;
            while(num>0){
              temp=num%10;
              if(temp==0 || i%temp!=0){//temp==0 condition to be checked to avoid division by zero
                check=false;
              }
              num/=10;
              }
            if(check){
                result.push_back(i);//.push_back() is a part of std::vector and it adds specified element to vector <int> result
            }
        }
        return result;
    }
};
int main(){
    Solution sol;
    vector <int> x;
    x=sol.selfDividingNumbers(1,225);
    for(int i=0;i<x.size();i++){
        cout<<x[i]<<" ";
    }
}
