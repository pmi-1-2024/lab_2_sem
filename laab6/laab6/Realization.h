#pragma once
#include "Transport.h"
#include "SpecialTransport.h"
#include "Passenger.h"
#include <iostream>
using namespace std;

template <typename T>
void applySpecialCondition(SpecialTransport<T>& transport) {
    cout << "Enter special condition for transport (, Expedited' for faster delivery): ";
    string condition;
    cin >> condition;

    transport.updateSpecialCondition(condition);
    transport.expediteDelivery();
    transport.printInfo();
}

template <typename T>
class TransportSystem {
private:
    Transport<T>** transports;
    T* passengers;
    bool* usedPassengers;
    int numTransports;
    int numPassengers;

public:
    TransportSystem() {
        cout << "Enter number of transports: ";
        cin >> numTransports;
        transports = new Transport<T>*[numTransports];

        cout << "Enter number of passengers: ";
        cin >> numPassengers;
        passengers = new T[numPassengers];
        usedPassengers = new bool[numPassengers] {false};

        for (int i = 0; i < numPassengers; ++i) {
            cout << "Enter name and age for passenger #" << i + 1 << ": ";
            cin >> passengers[i]; 
        }

        for (int i = 0; i < numTransports; ++i) {
            cout << "\nIs this a special transport? (1 - Yes, 0 - No): ";
            int isSpecial;
            cin >> isSpecial;

            int passengerIndex;
            cout << "Place passenger by number (1 to " << numPassengers << "): ";
            cin >> passengerIndex;
            while (passengerIndex < 1 || passengerIndex > numPassengers || usedPassengers[passengerIndex - 1]) {
                cout << "Invalid or already placed passenger. Try again: ";
                cin >> passengerIndex;
            }

            T assignedPassenger = passengers[passengerIndex - 1];
            usedPassengers[passengerIndex - 1] = true;

            double cost, maxLoad;
            string destination;
            cout << "Enter delivery cost, destination, and max load: ";
            cin >> cost >> destination >> maxLoad;

            if (isSpecial == 1)
                transports[i] = new SpecialTransport<T>(assignedPassenger, cost, destination, maxLoad);
            else
                transports[i] = new Transport<T>(assignedPassenger, cost, destination, maxLoad);
        }

        showMenu(); 
    }

    void showMenu() {
        int choice;
        do {
            cout << "\nMenu:\n";
            cout << "1. Update Passenger Info\n";
            cout << "2. Apply Special Condition (Expedited Delivery)\n";
            cout << "3. Show Transport Info\n";
            cout << "4. Distribute weight\n";
            cout << "5. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
            case 1: {
                int index;
                cout << "Enter transport number to update (1 to " << numTransports << "): ";
                cin >> index;
                if (index < 1 || index > numTransports) {
                    cout << "Invalid number!" << endl;
                    break;
                }
                string newName;
                int newAge;
                cout << "Enter new name and age for passenger: ";
                cin >> newName >> newAge;
                transports[index - 1]->updatePassengerInfo(newName, newAge);

                double newCost;
                cout << "Enter new delivery cost: ";
                cin >> newCost;
                transports[index - 1]->updateCost(newCost);

                cout << "Transport #" << index << " updated" << endl;
                break;
            }
            case 2:
                for (int i = 0; i < numTransports; i++) {
                    SpecialTransport<T>* special = dynamic_cast<SpecialTransport<T>*>(transports[i]);
                    if (special) {
                        cout << "\nFor transport #" << i + 1 << ":\n";
                        applySpecialCondition(*special); 
                    }
                }
                break;
            case 3:
                for (int i = 0; i < numTransports; i++) {
                    transports[i]->printInfo();
                }
                break;
            case 4: {
                double cargoWeight;
                cout << "\nEnter total cargo weight to distribute: ";
                cin >> cargoWeight;
                double remaining = cargoWeight;
                cout << "\nDistributing " << cargoWeight << "kg of cargo:\n";
                for (int i = 0; i < numTransports; i++) {
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
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice.\n";
            }
        } while (choice != 5);
    }

    ~TransportSystem() {
        for (int i = 0; i < numTransports; ++i)
            delete transports[i];
        delete[] transports;
        delete[] passengers;
        delete[] usedPassengers;
    }
};


template <typename T>
void createMenu() {
    TransportSystem<T> system;
};

