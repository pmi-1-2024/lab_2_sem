#include "radix_sort.h"

template <typename T>
T getMax(T arr[], int size) {
    T maxVal = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

template <typename T>
void countingSort(T arr[], int size, int exp) {
    T* output = new T[size];
    int count[10] = { 0 };

    for (int i = 0; i < size; i++) {
        count[(arr[i] / exp) % 10]++;
    }
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
    for (int i = size - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (int i = 0; i < size; i++) {
        arr[i] = output[i];
    }
    delete[] output;
}

void countingSortString(string arr[], int size, int exp) {
    string* output = new string[size];
    int count[256] = { 0 };

    for (int i = 0; i < size; i++) {
        count[(arr[i][exp])]++;
    }
    for (int i = 1; i < 256; i++) {
        count[i] += count[i - 1];
    }
    for (int i = size - 1; i >= 0; i--) {
        output[count[(arr[i][exp])] - 1] = arr[i];
        count[(arr[i][exp])]--;
    }
    for (int i = 0; i < size; i++) {
        arr[i] = output[i];
    }
    delete[] output;
}

void radixSortString(string arr[], int size) {
    int maxLen = 0;
    for (int i = 0; i < size; i++) {
        maxLen = max(maxLen, (int)arr[i].length());
    }
    for (int exp = maxLen - 1; exp >= 0; exp--) {
        countingSortString(arr, size, exp);
    }
}

template <typename T>
void countingSortStudent(T arr[], int size, int exp) {
    T* output = new T[size];
    int count[256] = { 0 };

    for (int i = 0; i < size; i++) {
        count[(arr[i].name[exp])]++;
    }
    for (int i = 1; i < 256; i++) {
        count[i] += count[i - 1];
    }
    for (int i = size - 1; i >= 0; i--) {
        output[count[(arr[i].name[exp])] - 1] = arr[i];
        count[(arr[i].name[exp])]--;
    }
    for (int i = 0; i < size; i++) {
        arr[i] = output[i];
    }
    delete[] output;
}

template <typename T>
void radixSortStudent(T arr[], int size) {
    int maxLen = 0;
    for (int i = 0; i < size; i++) {
        maxLen = max(maxLen, (int)arr[i].name.length());
    }
    for (int exp = maxLen - 1; exp >= 0; exp--) {
        countingSortStudent(arr, size, exp);
    }
}

template <typename T>
void radixSort(T arr[], int size) {
    T maxVal = getMax(arr, size);
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSort(arr, size, exp);
    }
}
template void radixSort<string>(string arr[], int size);

template void radixSort<int>(int arr[], int size);
template void radixSort<double>(double arr[], int size);
template void radixSort<Student>(Student arr[], int size);  
template void radixSortStudent<Student>(Student arr[], int size);  