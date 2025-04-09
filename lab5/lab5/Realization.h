#ifndef REALIZATION_H
#define SORTING_REALIZATION_H

#include <iostream>

using namespace std;

template <typename T, typename Compare>
void selectionSort(T* arr, int size, Compare comp) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (comp(arr[j], arr[minIndex])) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

template <typename T>
void printArray(T* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void showMenu();

#endif
