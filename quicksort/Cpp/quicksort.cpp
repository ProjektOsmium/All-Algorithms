#include <iostream>
using namespace std;

void swap(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

int partition(int array[], int low, int high) {
    int pivot = array[low + (high - low) / 2];
    int i = low - 1;
    int j = high + 1;
    while (1) {
        do {
            i++;
        } while(array[i] < pivot);

        do {
            j--;
        } while(array[j] > pivot);

        if (i>=j) {
            return j;
        }
        swap(&array[i], &array[j]);
    }
}

void quicksort(int array[], int low, int high) {
    if (low < high) {
        int part = partition(array, low, high);
        quicksort(array, low, part);
        quicksort(array, part + 1, high);
    }
}

void print_array(int array[], int array_len) {
    for (size_t i = 0; i < array_len - 1; i++) {
        cout << array[i] << ' ';
    }
    cout << array[array_len-1] << endl;
}

int main(int argc, char const *argv[]) {
    int array[] = {5, 7, 1, 3, 8, 2, 9, 4, 6};
    int array_len = sizeof(array)/sizeof(array[0]);

    print_array(array, array_len);

    cout << "Sorting..." << endl;
    quicksort(array, 0, array_len - 1);

    print_array(array, array_len);
    return 0;
}
