#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "Product.h"
#include <iostream>
#include <string>
using namespace std;


void menu() {
    cout << "Select the type of data to sort:\n";
    cout << "1. Array of integers\n"
        << "2. Array of doubles\n"
        << "3. Array of strings\n"
        << "4. Array of custom struct (Product)\n"
        << "5. Exit program\n"
        << "Enter your choice: ";
}

template <typename T>
bool ascending(const T& a, const T& b) {
    return a > b;
}

template <typename T>
bool descending(const T& a, const T& b) {
    return a < b;
}

template <typename T>
void shellSort(T arr[], int size) {
    if (size <= 1) return;
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; i++) {
            T temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

template <typename T>
void shellSort(T arr[], int size, bool (*comp)(const T&, const T&)) {
    if (size <= 1) return;
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; i++) {
            T temp = arr[i];
            int j;
            for (j = i; j >= gap && comp(arr[j - gap], temp); j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}


template <typename T>
void printArray(T arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


template <typename T>
void menu2(T arr[], int size) {
    cout << "Choose sorting type:\n";
    cout << "1. Base function (default sorting)\n";
    cout << "2. Custom function (choose comparator)\n";
    int choice;
    cin >> choice;

    switch (choice) {
    case 1:
        shellSort(arr, size);
        break;
    case 2: {
        cout << "Choose comparison method:\n";
        cout << "1. Ascending order\n";
        cout << "2. Descending order\n";
        int compChoice;
        cin >> compChoice;

        if (compChoice == 1) {
            shellSort(arr, size, ascending<T>);
        }
        else if (compChoice == 2) {
            shellSort(arr, size, descending<T>);
        }
        else {
            cout << "Invalid choice for comparison method!" << endl;
        }
        break;
    }
    default:
        cout << "Invalid sorting type choice!" << endl;
    }
    cout << "Sorted array: ";
    printArray(arr, size);
}

#endif
