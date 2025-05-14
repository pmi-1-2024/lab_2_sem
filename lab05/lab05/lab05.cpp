#include <iostream>
#include <string>
#include "cable.h"
#include "sort.h"

using namespace std;

int main() {
    const int intSize = 5;
    const int doubleSize = 5;
    const int strSize = 4;
    const int cableSize = 4;

    int intArr[intSize] = { 11, 2, 3, 5, 23 };
    double doubleArr[doubleSize] = { 5.1, 5.44, 1.2, 10.566, 2.22 };
    string strArr[strSize] = { "cyan", "apple", "addition", "lime" };
    Cable cableArr[cableSize] = {
        {"Fiber", "Red", 150},
        {"Copper", "Magenta", 100},
        {"Fiber", "Green", 200},
        {"Copper", "Cyan", 250}
    };

    insertionSort(intArr, intSize);
    insertionSort(doubleArr, doubleSize);
    insertionSort(strArr, strSize);
    insertionSort(cableArr, cableSize);

    cout << "Sorted int: ";
    printArray(intArr, intSize);

    cout << "Sorted double: ";
    printArray(doubleArr, doubleSize);

    cout << "Sorted string: ";
    printArray(strArr, strSize);

    cout << "Sorted cable: ";
    printArray(cableArr, cableSize);

    insertionSort(intArr, intSize, descComp<int>);
    insertionSort(doubleArr, doubleSize, descComp<double>);
    insertionSort(strArr, strSize, descComp<string>);
    insertionSort(cableArr, cableSize, descComp<Cable>);

    cout << "Sorted int(descending): ";
    printArray(intArr, intSize);

    cout << "Sorted double(descending): ";
    printArray(doubleArr, doubleSize);

    cout << "Sorted string(descending): ";
    printArray(strArr, strSize);

    cout << "Sorted cable(descending): ";
    printArray(cableArr, cableSize);

    return 0;
}