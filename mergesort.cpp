#include<iostream>
using namespace std;
void merge(int a[], int s, int e)
{
    int mid = (s+e)/2;
    int i = s;
    int j = mid + 1;
    int k = s;

    int fin[100];


    while(i<=mid && j<=e)
    {
    if(a[i]<a[j])
    {
        fin[k] = a[i];
        k++;
        i++;
    }

    else
    {
        fin[k] = a[j];
        k++;
        j++;
    }
    }

    while(i<=mid)
    {
        fin[k] = a[i];
    }

    while(j<=e)
    {
        fin[k] = a[j];
    }

    for(int i = s ; i <= e ; i++)
        a[i] = fin[i];
}
void mergesort(int a[], int s, int e)
{

    //1. Divide
    int mid = (s+e)/2;

    //2. Recursively sort two arrays
    mergesort(a,s,mid);
    mergesort(a,mid+1,e);

    //3. Merge the parts
    merge(a,s,e);

}


int main()
{
    int a[] = {1,4,2,6,3,5,9,8,7};
    int n = sizeof(a)/sizeof(a[0]);
    cout<<n;

    mergesort(a,0,n-1);

    for(int i = 0 ; i < n ; i++)
        cout<<a[i];
}
