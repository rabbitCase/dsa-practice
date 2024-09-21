//Leetcode Medium 189: Rotate Array by k places
#include <iostream>
using namespace std;
int main(){
    int n,i,j,a[100],k,temp;
    cin >> n;
    for(i=0;i<n;i++)
    cin >> a[i];
    cin>>k;
    for(i=0;i<k;i++){
        temp=a[n-1];//last element
        for(j=n-1;j>=0;j--){
            a[j]=a[j-1];
        }
        a[0]=temp;
    }
    cout << "\n";
    for(i=0;i<n;i++){
        cout << a[i] << " ";
    }
}
