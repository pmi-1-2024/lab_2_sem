#ifndef REALIZATION_H
#define SORTING_REALIZATION_H

#include <iostream>
#include "MobilePhone.h"
using namespace std;

template <typename T>
void selectionSort(T* arr, int size, bool (*compare)(T, T)) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (compare(arr[j], arr[minIndex])) {
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

bool compareInt(int a, int b);
bool compareDouble(double a, double b);
bool compareString(string a, string b);
bool compareByPrice(MobilePhone a, MobilePhone b);
bool compareByBrand(MobilePhone a, MobilePhone b);
bool stdCompare(const MobilePhone a, const MobilePhone b);



#endif


