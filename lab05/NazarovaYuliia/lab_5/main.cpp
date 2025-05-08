#include <iostream>
#include <string>
#include "QuickSort.h"
#include "Utils.h"
using namespace std;

static void showMenu() {
    cout << "=============== MENU ===============" << endl;
    cout << "1. Sort int array (recursive)" << endl;
    cout << "2. Sort int array (iterative)" << endl;
    cout << "3. Sort double array (recursive)" << endl;
    cout << "4. Sort double array (iterative)" << endl;
    cout << "5. Sort string array (recursive)" << endl;
    cout << "6. Sort string array (iterative)" << endl;
    cout << "0. Exit";
    cout << "====================================" << endl;
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
        
        int size;
        if (choice >= 1 && choice <= 6) {
            cout << "Enter the size of array: ";
            cin >> size;
            if (size <= 0) {
                cout << "Invalid size." << endl;
                continue;
            }
        }

        if (choice == 1 || choice == 2) {
            int* arr = new int[size];
            cout << "Enter " << size << " integers: ";
            inputArray(arr, size);

            cout << "Original: ";
            printArray(arr, size);

            if (choice == 1)
                quickSortRecursive(arr, 0, size - 1, compareInt);
            else
                quickSortIterative(arr, size, compareInt);

            cout << "Sorted:   ";
            printArray(arr, size);
            delete[] arr;
        }
        else if (choice == 3 || choice == 4) {
            double* arr = new double[size];
            cout << "Enter " << size << " doubles: ";
            inputArray(arr, size);

            cout << "Original: ";
            printArray(arr, size);

            if (choice == 3)
                quickSortRecursive(arr, 0, size - 1, compareDouble);
            else
                quickSortIterative(arr, size, compareDouble);

            cout << "Sorted:   ";
            printArray(arr, size);
            delete[] arr;
        }
        else if (choice == 5 || choice == 6) {
            string* arr = new string[size];
            cout << "Enter " << size << " strings: ";
            inputArray(arr, size);

            cout << "Original: ";
            printArray(arr, size);

            if (choice == 5)
                quickSortRecursive(arr, 0, size - 1, compareString);
            else
                quickSortIterative(arr, size, compareString);

            cout << "Sorted:   ";
            printArray(arr, size);
            delete[] arr;
        }
        else if (choice == 0) {
            cout << "Exiting...\n";
        }
        else {
            cout << "Invalid choice. Try again.\n";
        }

        cout << " " << endl;
    } while (choice != 0);

    return 0;
}
