#include <iostream>
#include <string>
#include "QuickSort.h"
#include "Utils.h"
using namespace std;

static void showMenu() {
    cout << "================ MENU ================\n";
    cout << "1. Sort int array\n";
    cout << "2. Sort double array\n";
    cout << "3. Sort string array\n";
    cout << "0. Exit\n";
    cout << "======================================\n";
}

int main() {
    int choice;
    do {
        showMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Try again.\n";
            continue;
        }

        if (choice == 1) {
            int size;
            cout << "Enter the size of int array: ";
            cin >> size;
            if (size <= 0) {
                cout << "Invalid size.\n";
                continue;
            }

            int* intArr = new int[size];
            cout << "Enter " << size << " integers: ";
            cin >> ArrayWrapper<int>(intArr, size);

            cout << "Original: " << ArrayWrapper<int>(intArr, size) << endl;
            quickSortRecursive(intArr, 0, size - 1, compareInt);
            cout << "Sorted:   " << ArrayWrapper<int>(intArr, size) << endl;

            delete[] intArr;
        }
        else if (choice == 2) {
            int size;
            cout << "Enter the size of double array: ";
            cin >> size;
            if (size <= 0) {
                cout << "Invalid size.\n";
                continue;
            }

            double* doubleArr = new double[size];
            cout << "Enter " << size << " doubles: ";
            cin >> ArrayWrapper<double>(doubleArr, size);

            cout << "Original: " << ArrayWrapper<double>(doubleArr, size) << endl;
            quickSortRecursive(doubleArr, 0, size - 1, compareDouble);
            cout << "Sorted:   " << ArrayWrapper<double>(doubleArr, size) << endl;

            delete[] doubleArr;
        }
        else if (choice == 3) {
            int size;
            cout << "Enter the size of string array: ";
            cin >> size;
            if (size <= 0) {
                cout << "Invalid size.\n";
                continue;
            }

            string* stringArr = new string[size];
            cout << "Enter " << size << " words: ";
            cin >> ArrayWrapper<string>(stringArr, size);

            cout << "Original: " << ArrayWrapper<string>(stringArr, size) << endl;
            quickSortRecursive(stringArr, 0, size - 1, compareString);
            cout << "Sorted:   " << ArrayWrapper<string>(stringArr, size) << endl;

            delete[] stringArr;
        }
        else if (choice == 0) {
            cout << "Exiting...\n";
        }
        else {
            cout << "Invalid choice. Try again.\n";
        }

        cout << "\n";
    } while (choice != 0);

    return 0;
}