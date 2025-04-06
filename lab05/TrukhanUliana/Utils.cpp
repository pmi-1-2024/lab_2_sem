#include "Utils.h"
using namespace std;

void menu() {
	cout << "1. Integers array" << endl;
	cout << "2. Doubles array" << endl;
	cout << "3. Strings array" << endl;
	cout << "4. Custom struct array" << endl;
	cout << "5. Exit" << endl;
	cout << "Enter your choice: ";
}

template <>
void bucketSort<string>(string array[], int n) {
    const int bucketCount = 26;
    const int bucketSize = 100;

    string** buckets = new string * [bucketCount];
    int* bucketSizes = new int[bucketCount] { 0 };

    for (int i = 0; i < bucketCount; i++) {
        buckets[i] = new string[bucketSize];
    }

    for (int i = 0; i < n; i++) {
        char firstChar = array[i][0];
        int bucketIndex = firstChar - 'a';

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

template<>
bool Comp<int>(int& a, int& b) {
    return (a % 10) > (b % 10);
}

template<>
bool Comp<string>(string& a, string& b) {
    return a.length() > b.length();
}

template<>
bool Comp<Student>(Student& a, Student& b) {
    if (a.surname != b.surname) return a.surname > b.surname;
    return a.name > b.name;
}

template <>
void bucketSort<string>(string array[], int n, bool (*comp)(string&, string&)) {
    const int bucketCount = 26;
    const int bucketSize = 100;

    string** buckets = new string * [bucketCount];
    int* bucketSizes = new int[bucketCount] { 0 };

    for (int i = 0; i < bucketCount; i++) {
        buckets[i] = new string[bucketSize];
    }

    for (int i = 0; i < n; i++) {
        char firstChar = array[i][0];
        int bucketIndex = firstChar - 'a';

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

