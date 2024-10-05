//CSES problemset (Sorting and Searching): Stick Lengths
/*Given an array containing lengths of n sticks, we have to modify the length of the sticks such that all of them are of equal lengths, we have to return the minimum cost to do so. Cost is calculated as the difference of abs(initial length - final length)*/
/*Concept: for minimum cost find the median of the array and calculate difference of every element with the median. All of the differences add to the cost*/ 
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
    sort(arr.begin(),arr.end());//sort before finding the median
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
