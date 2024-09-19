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
              if(temp==0 || i%temp!=0){
                check=false;
              }
              num/=10;
              }
            if(check){
                result.push_back(i);
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
