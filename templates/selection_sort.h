#pragma once
#include <iostream>
#include "utils.h"

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
template <typename T>
void selectionSort1(T arr[], int size, bool (*Comp)(T&, T&)) {
    for (int i = 0; i < size - 1; ++i) {
        int selectedIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (Comp(arr[j], arr[selectedIndex])) {
                selectedIndex = j;
            }
        }
        swap(arr[i], arr[selectedIndex]);
    }
}
