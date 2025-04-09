#pragma once
#include <iostream>

using namespace std;
template <typename T>
void selectionSort(T arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}
template <typename T, typename Comp>
void selectionSort(T arr[], int size, Comp comp) {
    for (int i = 0; i < size - 1; ++i) {
        int selectedIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (comp(arr[j], arr[selectedIndex])) {
                selectedIndex = j;
            }
        }
        swap(arr[i], arr[selectedIndex]);
    }
}
