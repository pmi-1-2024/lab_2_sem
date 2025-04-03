#pragma once
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

template <typename T>
void quickSortIterative(T arr[], int size, bool (*comp)(const T&, const T&)) {
    int* stack = new int[size];
    int top = -1;
    stack[++top] = 0;
    stack[++top] = size - 1;

    while (top >= 0) {
        int high = stack[top--];
        int low = stack[top--];
        int pi = partition(arr, low, high, comp);

        if (pi - 1 > low) {
            stack[++top] = low;
            stack[++top] = pi - 1;
        }
        if (pi + 1 < high) {
            stack[++top] = pi + 1;
            stack[++top] = high;
        }
    }
    delete[] stack;
}
