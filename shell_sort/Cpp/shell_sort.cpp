#include <iostream>
using namespace std;

void shellsort(int array[], int array_len) {
    int j, temp;
    for (size_t gap = array_len / 2; gap > 0; gap /= 2) {
        for (size_t i = gap; i < array_len; i++) {
            temp = array[i];
            for (j = i; j >= gap && array[j - gap] > temp; j -= gap) {
                array[j] = array[j - gap];
            }
            array[j] = temp;
        }
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
    shellsort(array, array_len);

    print_array(array, array_len);
    return 0;
}
