#pragma once
#include "Transport.h"
#include "SpecialTransport.h"

#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <fstream>
using namespace std;

template <typename T>
void inputInfo(Transport<T>* arr, int size) {
    for (int i = 0; i < size; i++) {
        try {
            cout << "Enter info for transport #" << i + 1 << " (cargo type, cost, destination, maxLoad): ";
            cin >> arr[i];
        }
        catch (const exception& e) {
            throw TransportException("Error during input: " + string(e.what()));
        }
    }
}

template <typename T>
void updateTransportInfo(Transport<T>* arr, int size) {
    try {
        int index;
        cout << "Enter the transport number to update (1 to " << size << "): ";
        cin >> index;

        if (index < 1 || index > size)
            throw out_of_range("Transport number out of range.");

        T newCargoType;
        double newCost;
        cout << "Enter new cargo type: ";
        cin >> newCargoType;
        cout << "Enter new delivery cost: ";
        cin >> newCost;

        arr[index - 1].updateCargoInfo(newCargoType, newCost);
        cout << "Transport #" << index << " info updated!" << endl;

    }
    catch (const exception& e) {
        cout << "Update error: " << e.what() << endl;
    }
}

template <typename T>
void applySpecialCondition(SpecialTransport<T>& transport) {
    try {
        cout << "Enter special condition (e.g., 'Expedited'): ";
        string condition;
        cin >> condition;
        transport.updateSpecialCondition(condition);
        transport.expediteDelivery();
        transport.printInfo();
    }
    catch (const exception& e) {
        cout << "Special condition error: " << e.what() << endl;
    }
}

template <typename T>
void distributeCargo(Transport<T>* arr, int size, double totalCargo) {
    try {
        if (totalCargo < 0)
            throw TransportException("Total cargo weight cannot be negative.");

        double remaining = totalCargo;
        cout << "\nDistributing " << totalCargo << "kg:\n";
        for (int i = 0; i < size && remaining > 0; i++) {
            double load = min(arr[i].getMaxLoad(), remaining);
            cout << "Transport #" << i + 1 << ": " << load << "kg\n";
            remaining -= load;
        }

        if (remaining > 0)
            cout << "\nCould not distribute " << remaining << "kg due to limits.\n";
        else
            cout << "\nAll cargo distributed.\n";

    }
    catch (const exception& e) {
        cout << "Cargo distribution error: " << e.what() << endl;
    }
}

template <typename T>
void createMenu() {
    try {
        int size;
        cout << "Enter number of transports: ";
        cin >> size;
        if (size <= 0) throw TransportException("Transport array size must be positive.");

        Transport<T>* transports = new Transport<T>[size];
        inputInfo(transports, size);

        int choice;
        do {
            cout << "\nMenu:\n1. Update Info\n2. Apply Special Condition\n3. Distribute Cargo\n4. Show Info\n5. Exit\nChoice: ";
            cin >> choice;

            switch (choice) {
            case 1:
                updateTransportInfo(transports, size);
                break;
            case 2:
                for (int i = 0; i < size; i++) {
                    SpecialTransport<T>* ptr = dynamic_cast<SpecialTransport<T>*>(&transports[i]);
                    if (ptr) {
                        cout << "For transport #" << i + 1 << ":\n";
                        applySpecialCondition(*ptr);
                    }
                }
                break;
            case 3:
                double cargo;
                cout << "Enter cargo weight: ";
                cin >> cargo;
                distributeCargo(transports, size, cargo);
                break;
            case 4:
                for (int i = 0; i < size; i++)
                    transports[i].printInfo();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
                break;
            }
        } while (choice != 5);

        delete[] transports;
    }
    catch (const exception& e) {
        cout << "Fatal error: " << e.what() << endl;
    }
}
