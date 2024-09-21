//CSES problemset: Arrays and Sorting
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n,sum=0,cost=0;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    sort(arr.begin(),arr.end());
    int median;
    if(n%2!=0){
        median =arr[n/2];
    }
    else{
        median=arr[((n/2-1)+(n/2))/2];
    }
    for(int i=0;i<n;i++){
        cost+=abs(arr[i]-median);
    }
    cout<<cost<<endl;
}