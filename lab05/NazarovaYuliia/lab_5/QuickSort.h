#pragma once
#include <iostream>
#include <string>
using namespace std;

template <typename T>
void inputArray(T* arr, int size) {
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }
}

template <typename T>
void printArray(T* arr, int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool compareInt(const int& a, const int& b);
bool compareDouble(const double& a, const double& b);
bool compareString(const string& a, const string& b);
