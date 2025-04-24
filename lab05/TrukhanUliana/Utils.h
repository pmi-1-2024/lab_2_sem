#ifndef UTILS_H
#define UTILS_H
#include "Student.h"
#include <iostream>
#include <string>
using namespace std;

void menu();

template <typename T>
void bubbleSort(T arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

template <typename T>
void bucketSort(T array[], int n) {
	T minVal = array[0];
	T maxVal = array[0];
	for (size_t i = 1; i < n; i++) {
		if (array[i] < minVal) minVal = array[i];
		if (array[i] > maxVal) maxVal = array[i];
	}

    int bucketCount = (maxVal - minVal) / 10 + 1;
    const int bucketSize = 100;

    T** buckets = new T * [bucketCount];
    int* bucketSizes = new int[bucketCount] { 0 };

    for (int i = 0; i < bucketCount; i++) {
        buckets[i] = new T[bucketSize];
    }

    for (int i = 0; i < n; i++) {
        int bucketIndex = int(((array[i] - minVal) * (bucketCount - 1)) / (maxVal - minVal + 1e-9));
        if (bucketSizes[bucketIndex] < bucketSize) {
            buckets[bucketIndex][bucketSizes[bucketIndex]++] = array[i];
        }
        else {
			throw "Bucket overflow!";
            return;
        }
    }

    int index = 0;
    for (int i = 0; i < bucketCount; i++) {
        if (bucketSizes[i] > 1) {
            bubbleSort(buckets[i], bucketSizes[i]);
        }
        for (int j = 0; j < bucketSizes[i]; j++) {
            array[index++] = buckets[i][j];
        }
    }

    for (int i = 0; i < bucketCount; i++) {
        delete[] buckets[i];
    }
    delete[] buckets;
    delete[] bucketSizes;
}

template <>
void bucketSort<string>(string array[], int n);


template <typename T>
bool Comp(T& a, T& b) {
	return a > b;
}

template<>
bool Comp<int>(int& a, int& b);

template<>
bool Comp<string>(string& a, string& b);

template<>
bool Comp<Student>(Student& a, Student& b);


template <typename T>
void bubbleSort(T arr[], int size, bool (*comp)(T&, T&)) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (comp(arr[j], arr[j + 1])) {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

template <typename T>
void bucketSort(T array[], int n, bool (*comp)(T&, T&)) {
    T minVal = array[0];
    T maxVal = array[0];
    for (size_t i = 1; i < n; i++) {
        if (array[i] < minVal) minVal = array[i];
        if (array[i] > maxVal) maxVal = array[i];
    }

    int bucketCount = (maxVal - minVal) / 10 + 1;
    const int bucketSize = 100;

    T** buckets = new T * [bucketCount];
    int* bucketSizes = new int[bucketCount] { 0 };

    for (int i = 0; i < bucketCount; i++) {
        buckets[i] = new T[bucketSize];
    }

    for (int i = 0; i < n; i++) {
        int bucketIndex = int(((array[i] - minVal) * (bucketCount - 1)) / (maxVal - minVal + 1e-9));
        if (bucketSizes[bucketIndex] < bucketSize) {
            buckets[bucketIndex][bucketSizes[bucketIndex]++] = array[i];
        }
        else {
            throw "Bucket overflow!";
            return;
        }
    }

    int index = 0;
    for (int i = 0; i < bucketCount; i++) {
        if (bucketSizes[i] > 1) {
            bubbleSort(buckets[i], bucketSizes[i], Comp);
        }
        for (int j = 0; j < bucketSizes[i]; j++) {
            array[index++] = buckets[i][j];
        }
    }

    for (int i = 0; i < bucketCount; i++) {
        delete[] buckets[i];
    }
    delete[] buckets;
    delete[] bucketSizes;
}

template <>
void bucketSort<string>(string array[], int n, bool (*comp)(string&, string&));

template <typename T>
void printArray(T array[], size_t n) {
    for (size_t i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

template <typename T>
void menu2(T arr[], int s) {
    cout << "1. Base function" << endl;
    cout << "2. Custom function" << endl;
    int choice2;
    cin >> choice2;
    switch (choice2) {
    case 1: {
        bucketSort(arr, s);
        break;
    }
    case 2: {
        bucketSort(arr, s, Comp<T>);
        break;
    }
    default:
        cout << "Invalid choice" << endl;
    }
    cout << "After sorting: ";
    printArray(arr, s);
}
#endif // UTILS_H
