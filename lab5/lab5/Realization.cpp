#include "Realization.h"
#include "MobilePhone.h"
#include <iostream>

using namespace std;

template <typename T>
void inputArray(T* arr, int size) {
    cout << "Enter " << size << " values: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

bool compareInt(int a, int b) {
    return a < b;
}

bool compareDouble(double a, double b) {
    return a < b;
}

bool compareString(string a, string b) {
    return a < b;
}

bool compareByPrice(MobilePhone a, MobilePhone b) {
    return a.getPrice() < b.getPrice();
}

bool compareByBrand(MobilePhone a, MobilePhone b) {
    return a.getBrand() < b.getBrand();
}

bool stdCompare( MobilePhone a,  MobilePhone b) {
    return a < b;
}


void showMenu() {
    while (true) {
        cout << "1. Sort integers\n";
        cout << "2. Sort doubles\n";
        cout << "3. Sort strings\n";
        cout << "4. Sort MobilePhones\n";
        cout << "5. Exit\n";
        cout << "Choose an option: ";

        int choice;
        cin >> choice;

        if (choice == 5) {
            cout << "Exiting program";
            break;
        }

        int size;
        cout << "Enter the number of elements: ";
        cin >> size;

        if (choice == 1) {
            int* arr = new int[size];
            inputArray(arr, size);
            selectionSort(arr, size, compareInt);
            printArray(arr, size);
            delete[] arr;
        }
        else if (choice == 2) {
            double* arr = new double[size];
            inputArray(arr, size);
            selectionSort(arr, size, compareDouble);
            printArray(arr, size);
            delete[] arr;
        }
        else if (choice == 3) {
            string* arr = new string[size];
            inputArray(arr, size);
            selectionSort(arr, size, compareString);
            printArray(arr, size);
            delete[] arr;
        }
        else if (choice == 4) {
            MobilePhone* phones = new MobilePhone[size];

            cout << "Enter name, brand, price, color, memory for each phone:\n";
            for (int i = 0; i < size; i++) {
                cout << "Phone " << i + 1 << ": ";
                cin >> phones[i];
            }

            cout << "\nSort by:\n1. Price\n2. Brand\n3. defoultSort\n Choose: ";
            int sortChoice;
            cin >> sortChoice;

            if (sortChoice == 1)
                selectionSort(phones, size, compareByPrice);
            else if (sortChoice == 2)
                selectionSort(phones, size, compareByBrand);
            else if(sortChoice == 3)
                selectionSort(phones, size, stdCompare);

            cout << "Sorted MobilePhones:\n";
            printArray(phones, size);
            delete[] phones;
        }
        else {
            cout << "Invalid option, try again.";
        }
    }
}
