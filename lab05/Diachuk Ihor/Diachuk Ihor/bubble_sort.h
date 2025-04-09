#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include <iostream>
#include <string>

using namespace std;

template <typename T, typename Compare>
void bubbleSort(T arr[], int size, Compare comp) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (comp(arr[j + 1], arr[j])) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

#endif