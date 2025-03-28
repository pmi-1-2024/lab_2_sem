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
            selectionSort(arr, size, [](int a, int b) { return a < b; });
            printArray(arr, size);
            delete[] arr;
        }
        else if (choice == 2) {
            double* arr = new double[size];
            inputArray(arr, size);
            selectionSort(arr, size, [](double a, double b) { return a < b; });
            printArray(arr, size);
            delete[] arr;
        }
        else if (choice == 3) {
            string* arr = new string[size];
            inputArray(arr, size);
            selectionSort(arr, size, [](string a, string b) { return a < b; });
            printArray(arr, size);
            delete[] arr;
        }
        else if (choice == 4) {
            MobilePhone* phones = new MobilePhone[size];

            cout << "Enter name, brand, price, color, memory for each phone:\n";
            for (int i = 0; i < size; i++) {
                cout << "Phone " << i + 1 << ": ";
                cin >> phones[i].name >> phones[i].brand >> phones[i].price >> phones[i].color >> phones[i].memory;
            }

            cout << "\nSort by:\n1. Price\n2. Brand\nChoose: ";
            int sortChoice;
            cin >> sortChoice;

            if (sortChoice == 1)
                selectionSort(phones, size, compareByPrice);
            else
                selectionSort(phones, size, compareByBrand);

            cout << "Sorted MobilePhones:\n";
            printArray(phones, size);
            delete[] phones;
        }
        else {
            cout << "Invalid option,try again.";
        }
    }
}