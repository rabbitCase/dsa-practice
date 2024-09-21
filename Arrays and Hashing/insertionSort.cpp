#include <iostream>
using namespace std;
int main(){
    int i,j,a[100],key,n;
    cout << "Enter no of elements: ";
    cin>> n;
    cout<<"\nEnter elements: \n";
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    for(i=1;i<n;i++){
        key=a[i];
        j=i-1;
        while(j>=0 && a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
    for(i=0;i<n;i++)
    cout << a[i]<<" ";

}