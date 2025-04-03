#include "QuickSort.h"
#include <iostream>
using namespace std;

template <typename T>
int partition(T arr[], int low, int high, bool (*comp)(const T&, const T&)) {
    T pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (comp(arr[j], pivot)) {
            swap(arr[++i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

template <typename T>
void quickSortRecursive(T arr[], int low, int high, bool (*comp)(const T&, const T&)) {
    if (low < high) {
        int pi = partition(arr, low, high, comp);
        quickSortRecursive(arr, low, pi - 1, comp);
        quickSortRecursive(arr, pi + 1, high, comp);
    }
}