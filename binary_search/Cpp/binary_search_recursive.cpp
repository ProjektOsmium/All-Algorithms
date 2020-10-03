#include <iostream>
using namespace std;

int binarySearch(int arr[], int start, int end, int item) {
	if (start <= end) {
            int mid = start + (end - start) / 2; 
            if (arr[mid] == item) {
                  return mid; 
            } else if (arr[mid] > item) {
                  return binarySearch(arr, start, mid - 1, item); 
            } else {
                  return binarySearch(arr, mid + 1, end, item); 
            }
      }
	return -1;
}

int main() {
	int arr[] = {1, 3, 4, 13, 60};
	int n = sizeof(arr) / sizeof(arr[0]);
	int x = 60;
	int result = binarySearch(arr, 0, n-1, x);
	cout << "Index of " << x << " in array is: " << result << endl;
	return 0;
}
