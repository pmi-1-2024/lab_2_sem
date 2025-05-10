#include <iostream>
#include <string>
#include "selection_sort.h"
#include "person.h"
#include "utils.h"

using namespace std;

int main() {
    int choice;

    do {
        cout << "Choose the data to sort";
        cout << "\n1. Integers\n2. Doubles\n3. Strings\n4. People`s data\n0. Exit\n";
        cout << "Your choice: ";
        cin >> choice;

        if (choice == 0) {
            cout << "Exiting...\n";
        }
        int size;
        cout << "Enter number of elements: ";
        cin >> size;

        switch (choice) {
        case 1: {
            int* arr = new int[size];
            inputArray(arr, size);
            selectionSort(arr, size);
            cout << "After sorting: ";
            printArray(arr, size);
            delete[] arr;
            break;
        }

        case 2: {
            double* arr = new double[size];
            inputArray(arr, size);
            selectionSort(arr, size);
            cout << "After sorting: ";
            printArray(arr, size);
            delete[] arr;
            break;
        }

        case 3: {
            string* arr = new string[size];
            inputArray(arr, size);
            selectionSort(arr, size);
            cout << "After sorting: ";
            printArray(arr, size);
            delete[] arr;
            break;
        }

        case 4: {
            Person* arr = new Person[size];
            inputArray(arr, size);

            int personChoice;
            cout << "Sort by:\n1. Age\n2. Name\nYour choice: ";
            cin >> personChoice;

            switch (personChoice) {
            case 1:
                selectionSort(arr, size);
                break;
            case 2:
                selectionSort1(arr, size, personComp);
                break;
            default:
                cout << "Try again.\n";
                break;
            }

            cout << "After sorting: ";
            printArray(arr, size);
            delete[] arr;
            break;
        }

        default:
            cout << "Try again.\n";
            break;
        }


    } while (choice !=0);

    return 0;
}
