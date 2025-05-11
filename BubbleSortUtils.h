#pragma once
#include <iostream>
#include <string>
#include "UserDefinedType.h"
using namespace std;

template <typename T>
bool DefaultCompare(T& a, T& b) {
    return a > b;
}

bool CompareIntLastDigit(int& a, int& b);
bool CompareDoubleIntegerPart(double& a, double& b);
bool CompareStringLength(string& a, string& b);
bool CompareStudentSurnameLength(UserType& a, UserType& b);

template <typename T>
void BubbleSortBasic(T data[], size_t len) {
    for (size_t i = 0; i < len - 1; ++i)
    {
        for (size_t j = 0; j < len - i - 1; ++j)
        {
            if (data[j] > data[j + 1])
            {
                swap(data[j], data[j + 1]);
            }
        }
    }
}

template <typename T>
void BubbleSortWithCompare(T data[], size_t len, bool (*CompareFunc)(T&, T&)) {
    for (size_t i = 0; i < len - 1; ++i)
    {
        for (size_t j = 0; j < len - i - 1; ++j)
        {
            if (CompareFunc(data[j], data[j + 1]))
            {
                swap(data[j], data[j + 1]);
            }
        }
    }
}

template <typename T>
void DisplayArray(T arr[], size_t len) {
    for (size_t i = 0; i < len; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

template <typename T>
void FillArray(T arr[], size_t len) {
    cout << "\nInput elements of the array:\n";
    for (size_t i = 0; i < len; ++i)
    {
        cin >> arr[i];
    }
}

void ShowMainMenu();
void HandleUserChoice(int selection);

