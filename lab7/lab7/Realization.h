#pragma once
#include "Transport.h"
#include "SpecialTransport.h"
#include "Passenger.h"
#include <iostream>
#include <stdexcept>

using namespace std;


class InvalidPassengerCountException : public runtime_error {
public:
    InvalidPassengerCountException(const string& message)
        : runtime_error(message) {}
};

template <typename T>
void applySpecialCondition(SpecialTransport<T>& transport) {
    cout << "Enter special condition for transport ('Expedited' for faster delivery): ";
    string condition;
    cin >> condition;

    transport.updateSpecialCondition(condition);
    transport.expediteDelivery();
    transport.printInfo();
}

template <typename T>
void createMenu() {
    try {
        int size;
        cout << "Enter number of transports: ";
        cin >> size;

        if (cin.fail()) throw invalid_argument("Invalid input for number of transports");
        if (size <= 0)  throw invalid_argument("Number of transports must be positive"); 

        int numPassengers;
        cout << "Enter info for " << size << " passengers: ";
        cin >> numPassengers;

        if (cin.fail()) throw invalid_argument("Invalid input for number of passengers");
        if (numPassengers < size) {
            throw InvalidPassengerCountException("Error: Not enough passengers for the number of transports");
        }
        if (numPassengers > size) {
            throw InvalidPassengerCountException("Error: Too many passengers compared to the number of transports");
        }

        Transport<T>** transports = new Transport<T>*[size];
        T* passengers = new T[numPassengers];
        bool* usedPassengers = new bool[numPassengers];

        for (int i = 0; i < numPassengers; ++i) {
            cout << "Enter name and age for passenger #" << i + 1 << ": ";
            cin >> passengers[i];
            if (cin.fail()) throw invalid_argument("Invalid input for passenger!");
            usedPassengers[i] = false;
        }

        for (int i = 0; i < size; i++) {
            cout << "\nIs this a special transport? (1 - Yes, 0 - No): ";
            int isSpecial;
            cin >> isSpecial;
            if (cin.fail() || (isSpecial != 0 && isSpecial != 1)) {
                throw invalid_argument("Invalid input for special transport selection");
            }

            int passengerIndex;
            cout << "Place passenger by number (1 to " << numPassengers << "): ";
            cin >> passengerIndex;
            while (passengerIndex < 1 || passengerIndex > numPassengers || usedPassengers[passengerIndex - 1]) {
                cout << "Invalid or already placed passenger. Try again: ";
                cin >> passengerIndex;
            }

            T assignedPassenger = passengers[passengerIndex - 1];
            usedPassengers[passengerIndex - 1] = true;

            double cost;
            string destination;
            double maxLoad;
            cout << "Enter delivery cost, destination, and max load: ";
            cin >> cost >> destination >> maxLoad;
            if (cin.fail() || cost < 0 || maxLoad < 0) {
                throw invalid_argument("Invalid delivery cost or max load input");
            }

            if (isSpecial == 1) {
                transports[i] = new SpecialTransport<T>(assignedPassenger, cost, destination, maxLoad);
            }
            else {
                transports[i] = new Transport<T>(assignedPassenger, cost, destination, maxLoad);
            }
        }

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

            if (cin.fail()) throw invalid_argument("Invalid input for menu choice");

            switch (choice) {
            case 1: {
                int index;
                cout << "Enter transport number to update (1 to " << size << "): ";
                cin >> index;
                if (index < 1 || index > size) {
                    throw out_of_range("Invalid transport number");
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
                for (int i = 0; i < size; i++) {
                    SpecialTransport<T>* special = dynamic_cast<SpecialTransport<T>*>(transports[i]);
                    if (special) {
                        cout << "\nFor transport #" << i + 1 << ":\n";
                        applySpecialCondition(*special);
                    }
                }
                break;
            case 3:
                for (int i = 0; i < size; i++) {
                    transports[i]->printInfo();
                }
                break;
            case 4: {
                double cargoWeight;
                cout << "\nEnter total cargo weight to distribute: ";
                cin >> cargoWeight;
                if (cin.fail() || cargoWeight < 0) throw invalid_argument("Invalid cargo weight");

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
            case 5:
                cout << "BB\n";
                break;
            default:
                cout << "Invalid choice.\n";
            }
        } while (choice != 5);

        for (int i = 0; i < size; i++) {
            delete transports[i];
        }
        delete[] transports;
        delete[] passengers;
        delete[] usedPassengers;

    }
    catch (const InvalidPassengerCountException& ex) {
        cerr << "Passenger count error: " << ex.what() << endl;
        exit(EXIT_FAILURE);
    }
    catch (const invalid_argument& ex) {
        cerr << "Invalid input: " << ex.what() << endl;
        exit(EXIT_FAILURE);
    }
    catch (const out_of_range& ex) {
        cerr << "Out of range error: " << ex.what() << endl;
        exit(EXIT_FAILURE);
    }
    catch (const exception& ex) {
        cerr << "Exception: " << ex.what() << endl;
        exit(EXIT_FAILURE);
    }
    catch (...) {
        cerr << "Unknown error occurred" << endl;
        exit(EXIT_FAILURE);
    }
}
