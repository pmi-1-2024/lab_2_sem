#pragma once
#include <iostream>
#include <string>
using namespace std;

template<typename T>
void insertionSort(T arr[], int size) {
    for (int i = 1; i < size; ++i) {
        T key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

template<typename T>
bool descComp(const T& a, const T& b) {
    return a > b;
}

template<>
bool descComp<string>(const string& a, const string& b) {
    return a > b;
}

template<typename T, typename C>
void insertionSort(T arr[], int size, C comp) {
    for (int i = 1; i < size; ++i) {
        T key = arr[i];
        int j = i - 1;
        while (j >= 0 && comp(key, arr[j])) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

template<typename T>
void printArray(T arr[], int size) {
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}