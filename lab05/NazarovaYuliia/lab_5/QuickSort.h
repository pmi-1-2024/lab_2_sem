#pragma once
#include <iostream>
#include <string>
using namespace std;

template <typename T>
struct ArrayWrapper {
    T* arr;
    int size;
    ArrayWrapper(T* a, int s) : arr(a), size(s) {}
};

template <typename T>
ostream& operator<<(ostream& os, const ArrayWrapper<T>& aw) {
    for (int i = 0; i < aw.size; ++i) {
        os << aw.arr[i] << " ";
    }
    return os;
}

template <typename T>
istream& operator>>(istream& is, const ArrayWrapper<T>& aw) {
    for (int i = 0; i < aw.size; ++i) {
        is >> aw.arr[i];
    }
    return is;
}

bool compareInt(const int& a, const int& b);
bool compareDouble(const double& a, const double& b);
bool compareString(const string& a, const string& b);