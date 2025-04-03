#pragma once
#include <cstring>
#include <iostream>
using namespace std;

bool LessString(const char* a, const char* b) {
    return strcmp(a, b) < 0;
}

template <typename T>
void heapify(T arr[], int n, int i, bool (*comp)(const T&, const T&)) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && comp(arr[left], arr[largest]))
        largest = left;

    if (right < n&& comp(arr[right], arr[largest]))
        largest = right;

    if (largest != i) {
        T temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest, comp);
    }
}

template <typename T>
void sort(T arr[], int n, bool (*comp)(const T&, const T&)) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, comp);

    for (int i = n - 1; i > 0; i--) {
        T temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0, comp);
    }
}

template <typename T>
void print(T arr[], int n) {
    for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
    cout << endl;
}