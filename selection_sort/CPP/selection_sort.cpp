#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,i,j;
    cout<<"Length of array\n";
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++){
        cout<<"elements :";
        cin>>arr[i];
    }
    for(j=0;j<n-1;j++){
        for(int z=j+1;z<n;z++){
            if(arr[j]>arr[z]){
                int temp=arr[j];
                arr[j]=arr[z];
                arr[z]=temp;
            }
        }
    }
    cout<<"Sorted Array\n";
    for(i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}