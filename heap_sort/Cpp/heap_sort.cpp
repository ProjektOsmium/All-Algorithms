#include <iostream>
using namespace std;

int left(int i) {
  return 2*i + 1;
}

int right(int i) {
  return 2*i + 2;
}

void swap(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

void bubble_down(int array[], int i, int array_len) {
    int largest = i, l = left(i), r = right(i);

    if (l < array_len && array[l] > array[largest])
        largest = l;
    if (r < array_len && array[r] > array[largest])
        largest = r;
    if (largest != i) {
        swap(&array[i], &array[largest]);
        bubble_down(array, largest, array_len);
    }
}

void heapsort(int array[], int array_len) {
    
    for (int i = array_len / 2 - 1; i >= 0; i--) {
        bubble_down(array, i, array_len);
    }

    for (int i = array_len - 1; i >= 0; i--) {
        swap(array[0], array[i]);
        bubble_down(array, 0, i);
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
    heapsort(array, array_len);

    print_array(array, array_len);
    return 0;
}
