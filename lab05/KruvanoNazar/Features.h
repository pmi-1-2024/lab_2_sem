#ifndef FEATURES_H
#define FEATURES_H
#include <iostream>
#include <string>
#include "StudentStruct.h"
using namespace std;

template <typename T>
bool Comp( T& first, T& second) {
    return first > second;
}
template <typename T>
void BubbleSort1(T arr[], size_t size) {
    for (size_t i = 0; i < size - 1; i++) {
        for (size_t j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
template <typename T>
void BubbleSort2(T arr[], size_t size, bool (*Comp)( T&, T&)) {
    for (size_t i = 0; i < size - 1; i++) {
        for (size_t j = 0; j < size - i - 1; j++) {
            if (Comp(arr[j], arr[j + 1])) { 
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
template <typename T>
void PrintArr(T arr[], size_t size) {
    for (size_t i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}
template <typename T>
void EnterElem(T arr[], size_t size) {
    cout << "\nEnter array`s elements: ";
    for (size_t i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

void startmenu();
void Arraymenu(int choice);

#endif
