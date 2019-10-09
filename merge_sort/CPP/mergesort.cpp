#include<iostream>
#include<stdlib.h>
using namespace std;
int partition(int a[], int low, int high) 
{ 
    int pivot = a[high];     
    int i = (low - 1);  
  
    for (int j = low; j <= high- 1; j++) 
    { 
        if (a[j] <= pivot) 
        { 
            i++;    
            swap(a[i], a[j]); 
        } 
    } 
    swap(a[i + 1], a[high]); 
    return (i + 1); 
}
void quickSort(int a[], int low, int high) 
{ 
    if (low < high) 
    {
        int p = partition(a, low, high); 
  		quickSort(a, low, p - 1); 
        quickSort(a, p + 1, high); 
    } 
} 

void merge(int *a, int low, int high, int mid)
{
	int i, j, k, temp[high-low+1]; // We have low to mid and mid+1 to high already sorted.
	i = low;
	k = 0;
	j = mid + 1;
	while (i <= mid && j <= high)
	{
		if (a[i] < a[j])
		{
			temp[k] = a[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = a[j];
			k++;
			j++;
		}
	}
	while (i <= mid) //remaining elements
	{
		temp[k] = a[i];
		k++;
		i++;
	}
	while (j <= high)
	{
		temp[k] = a[j];
		k++;
		j++;
	}
	for (i = low; i <= high; i++)
	{
		a[i] = temp[i-low];
	}
}

void mergeSort(int *a, int low, int high)
{
	int mid;
	if (low < high)
	{
		mid=(low+high)/2;
		mergeSort(a, low, mid);
		mergeSort(a, mid+1, high);
		merge(a, low, high, mid);
	}
} 

int main()
{
	int n;
	cout<<"Enter size of array: ";
	cin>>n;
	int a[n];
	cout<<"Enter array elements: ";
	for(int i=0;i<n;i++)
		cin>>a[i];
	mergeSort(a,0,n-1);
	cout<<"Sorted array: ";
	for(int i =0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}