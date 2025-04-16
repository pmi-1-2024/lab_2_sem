#pragma once
#include <cstring>
#include <iostream>
using namespace std;

bool LessString(const char* a, const char* b) {
    return strcmp(a, b) < 0;
}

template <typename T>
bool defaultComp(const T& a, const T& b) {
    return a < b;
}

template <typename T>
void heapify(T arr[], int n, int i, bool (*comp)(const T&, const T&)) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && comp(arr[largest], arr[left]))
        largest = left;

    if (right < n&& comp(arr[largest], arr[right]))
        largest = right;

    if (largest != i) {
        T temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest, comp);
    }
}

template <class T>
void sort1(T a[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i, defaultComp<T>);

    for (int i = n - 1; i > 0; i--) {
        T temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        heapify(a, i, 0, defaultComp<T>);
    }
}

template <class T>
void sort2(T a[], int n, bool (*Comp)(const T&, const T&)) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i, Comp);

    for (int i = n - 1; i > 0; i--) {
        T temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        heapify(a, i, 0, Comp);
    }
}

template <typename T>
void print(T arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}