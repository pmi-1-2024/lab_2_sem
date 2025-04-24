#pragma once
#include "Transport.h"
#include "SpecialTransport.h"

#include <iostream>
using namespace std;

//template <typename T>
//void inputInfo(Transport<T>* arr, int size) {
//    for (int i = 0; i < size; i++) {
//        cout << "Enter info for transport #" << i + 1 << " (cargo type, cost, destination, maxLoad): ";
//        cin >> arr[i];
//    }
//}

//template <typename T>
//void updateTransportInfo(Transport<T>* arr, int size) {
//    int index;
//    cout << "Enter the transport number to update (1 to " << size << "): ";
//    cin >> index;
//    if (index < 1 || index > size) {
//        cout << "Invalid transport number!" << endl;
//        return;
//    }
//
//    T newCargoType;
//    double newCost;
//    cout << "Enter new cargo type: ";
//    cin >> newCargoType;
//    cout << "Enter new delivery cost: ";
//    cin >> newCost;
//
//    arr[index - 1].updateCargoInfo(newCargoType, newCost);
//    cout << "Transport #" << index << " info updated!" << endl;
//}

template <typename T>
void applySpecialCondition(SpecialTransport<T>& transport) {
    cout << "Enter special condition for transport (, Expedited' for faster delivery): ";
    string condition;
    cin >> condition;

    transport.updateSpecialCondition(condition);
    transport.expediteDelivery();
    transport.printInfo();  
}

//template <typename T>
//void distributeCargo(Transport<T>* arr, int size, double totalCargo) {
//    double remaining = totalCargo;
//    cout << "\nDistributing " << totalCargo << "kg of cargo:\n";
//    for (int i = 0; i < size; i++) {
//        if (remaining <= 0) break;
//        double load = min(arr[i].getMaxLoad(), remaining);
//        cout << "Transport #" << i + 1 << ": " << load << "kg\n";
//        remaining -= load;
//    }
//    if (remaining > 0) {
//        cout << "\nCould not distribute " << remaining << "kg of cargo due to capacity limits.\n";
//    }
//    else {
//        cout << "\nAll cargo distributed successfully.\n";
//    }
//}

template <typename T>
void createMenu() {
    int size;
    cout << "Enter the number of transports: ";
    cin >> size;

    
    Transport<T>** transports = new Transport<T>*[size];

    for (int i = 0; i < size; i++) {
        cout << "\nIs this a special transport? (1 - Yes, 0 - No): ";
        int isSpecial;
        cin >> isSpecial;

        if (isSpecial == 1) {
            transports[i] = new SpecialTransport<T>();
        }
        else {
            transports[i] = new Transport<T>();
        }

        cout << "Enter info for transport #" << i + 1 << " (cargo type, cost, destination, maxLoad): ";
        cin >> *transports[i];
    }

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Update Transport Info\n";
        cout << "2. Apply Special Condition (Expedited Delivery)\n";
        cout << "3. Distribute Cargo\n";
        cout << "4. Show Transport Info\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int index;
            cout << "Enter the transport number to update (1 to " << size << "): ";
            cin >> index;
            if (index < 1 || index > size) {
                cout << "Invalid transport number!" << endl;
                break;
            }
            T newCargoType;
            double newCost;
            cout << "Enter new cargo type: ";
            cin >> newCargoType;
            cout << "Enter new delivery cost: ";
            cin >> newCost;
            transports[index - 1]->updateCargoInfo(newCargoType, newCost);
            cout << "Transport #" << index << " info updated!" << endl;
            break;
        }
        case 2:
            for (int i = 0; i < size; i++) {
                SpecialTransport<T>* special = dynamic_cast<SpecialTransport<T>*>(transports[i]);
                if (special != nullptr) {
                    cout << "\nFor transport #" << i + 1 << ":\n";
                    applySpecialCondition(*special);
                }
            }
            break;
        case 3: {
            double cargoWeight;
            cout << "\nEnter total cargo weight to distribute: ";
            cin >> cargoWeight;
            double remaining = cargoWeight;
            cout << "\nDistributing " << cargoWeight << "kg of cargo:\n";
            for (int i = 0; i < size; i++) {
                if (remaining <= 0) break;
                double load = min(transports[i]->getMaxLoad(), remaining);
                cout << "Transport #" << i + 1 << ": " << load << "kg\n";
                remaining -= load;
            }
            if (remaining > 0) {
                cout << "\nCould not distribute " << remaining << "kg of cargo due to capacity limits.\n";
            }
            else {
                cout << "\nAll cargo distributed successfully.\n";
            }
            break;
        }
        case 4:
            cout << "\nDisplaying transport info:\n";
            for (int i = 0; i < size; i++) {
                transports[i]->printInfo();
            }
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice, try again.\n";
            break;
        }
    } while (choice != 5);

   
    for (int i = 0; i < size; i++) {
        delete transports[i];
    }
    delete[] transports;
}

