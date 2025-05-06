#include "Cargo.h"
#include "Passenger.h"
#include "Transport.h"
#include "SpecialTransport.h"
#include <fstream>
#include <iostream>

const int INITIAL_SIZE = 10;

enum class TransportType { CARGO, PASSENGER };

static void resizeArray(Transport<Cargo>**& arr, int& capacity) {
    int newCap = capacity * 2;
    Transport<Cargo>** newArr = new Transport<Cargo>*[newCap];
    for (int i = 0; i < capacity; ++i) {
        newArr[i] = arr[i];
    }
    delete[] arr;
    arr = newArr;
    capacity = newCap;
}

static void resizeArray(Transport<Passenger>**& arr, int& capacity) {
    int newCap = capacity * 2;
    Transport<Passenger>** newArr = new Transport<Passenger>*[newCap];
    for (int i = 0; i < capacity; ++i) {
        newArr[i] = arr[i];
    }
    delete[] arr;
    arr = newArr;
    capacity = newCap;
}

static void saveToFile(Transport<Cargo>** cargoArr, int cargoSize,
    Transport<Passenger>** passengerArr, int passengerSize) {
    ofstream fout("Text.txt");
    if (!fout.is_open()) {
        cerr << "Error opening a file for writing." << endl;
        return;
    }
    for (int i = 0; i < cargoSize; ++i) {
        SpecialTransport<Cargo>* st = dynamic_cast<SpecialTransport<Cargo>*>(cargoArr[i]);
        fout << "CARGO " << cargoArr[i]->getCargo().getName() << " "
            << cargoArr[i]->getCargo().getWeight() << " "
            << cargoArr[i]->getDestination() << " "
            << cargoArr[i]->getCost() << " "
            << (st ? 1 : 0) << endl;
    }

    for (int i = 0; i < passengerSize; ++i) {
        if (passengerArr[i] == nullptr) {
            continue;  
        }

        SpecialTransport<Passenger>* st = dynamic_cast<SpecialTransport<Passenger>*>(passengerArr[i]);
        fout << "PASSENGER "
            << passengerArr[i]->getCargo().getName() << " "
            << passengerArr[i]->getCargo().getAge() << " "
            << passengerArr[i]->getDestination() << " "
            << passengerArr[i]->getCost() << " "
            << (st != nullptr ? 1 : 0) << endl;  
    }
    fout.close();
}

int main() {
    int cargoCapacity = INITIAL_SIZE;
    int passengerCapacity = INITIAL_SIZE;
    int cargoSize = 0;
    int passengerSize = 0;

    Transport<Cargo>** cargoTransports = new Transport<Cargo>*[cargoCapacity];
    Transport<Passenger>** passengerTransports = new Transport<Passenger>*[passengerCapacity];


    ifstream file("Text.txt");
    if (file) {
        string type, name, destination;
        double value, cost;
        bool special;

        while (file >> type >> name >> value >> destination >> cost >> special) {
            if (type == "CARGO") {
                if (cargoSize >= cargoCapacity)
                    resizeArray(cargoTransports, cargoCapacity);
                Cargo cargo(name, value);
                if (special)
                    cargoTransports[cargoSize++] = new SpecialTransport<Cargo>(cargo, destination.c_str(), cost, true);
                else
                    cargoTransports[cargoSize++] = new Transport<Cargo>(cargo, destination.c_str(), cost);
            }
            else if (type == "PASSENGER") {
                if (passengerSize >= passengerCapacity)
                    resizeArray(passengerTransports, passengerCapacity);
                Passenger passenger(name, static_cast<int>(value));
                if (special)
                    passengerTransports[passengerSize++] = new SpecialTransport<Passenger>(passenger, destination.c_str(), cost, true);
                else
                    passengerTransports[passengerSize++] = new Transport<Passenger>(passenger, destination.c_str(), cost);
            }
        }
        file.close();
    }

    TransportType transportType = TransportType::CARGO;

    int choice;
    do {
        cout << "========MENU================" << endl;
        cout << "1. Select the type of transportation (cargo/passengers)" << endl;
        cout << "2. Show all transportations" << endl;
        cout << "3. Show discounts (10%)" << endl;
        cout << "4. Add new transportation" << endl;
        cout << "5. Save to file" << endl;
        cout << "0. Exit" << endl;
        cout << "============================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int typeChoice;
            cout << "Select the type of transportation:\n1. Cargo\n2. Passengers\nChoise: ";
            cin >> typeChoice;
            transportType = (typeChoice == 1) ? TransportType::CARGO : TransportType::PASSENGER;
            break;
        }
        case 2: {
            if (transportType == TransportType::CARGO) {
                cout << "\n=== CARGO ===" << endl;
                for (int i = 0; i < cargoSize; ++i) {
                    cout << "Transportation #" << i + 1 << ":" << endl;
                    cargoTransports[i]->print();
                }
            }
            else {
                cout << "\n=== PASSENGERS ===" << endl;
                for (int i = 0; i < passengerSize; ++i) {
                    cout << "Transportation #" << i + 1 << ":" << endl;
                    passengerTransports[i]->print();
                }
            }
            break;
        }
        case 3: {
            if (transportType == TransportType::CARGO) {
                for (int i = 0; i < cargoSize; ++i) {
                    cout << "With a 10% discount: " << cargoTransports[i]->calculateDiscount(10) << " UAH" << endl;
                }
            }
            else {
                for (int i = 0; i < passengerSize; ++i) {
                    cout << "With a 10% discount: " << passengerTransports[i]->calculateDiscount(10) << " UAH" << endl;
                }
            }
            break;
        }
        case 4: {
            string name, destination;
            double weightOrAge, cost;
            bool isSpecial;

            cout << "Eneter name: ";
            cin >> name;
            if (transportType == TransportType::CARGO) {
                cout << "Eneter weight (kg): ";
                cin >> weightOrAge;
            }
            else {
                cout << "Eneter the passegers age: ";
                cin >> weightOrAge;
            }
            cout << "Eneter destination: ";
            cin >> destination;
            cout << "Eneter the cost: ";
            cin >> cost;
            cout << "Special conditions (1 - yes, 0 - no): ";
            cin >> isSpecial;

            if (transportType == TransportType::CARGO) {
                if (cargoSize >= cargoCapacity)
                    resizeArray(cargoTransports, cargoCapacity);
                Cargo cargo(name, weightOrAge);
                if (isSpecial)
                    cargoTransports[cargoSize++] = new SpecialTransport<Cargo>(cargo, destination.c_str(), cost, true);
                else
                    cargoTransports[cargoSize++] = new Transport<Cargo>(cargo, destination.c_str(), cost);
            }
            else {
                if (passengerSize >= passengerCapacity)
                    resizeArray(passengerTransports, passengerCapacity);
                Passenger passenger(name, static_cast<int>(weightOrAge));
                if (isSpecial)
                    passengerTransports[passengerSize++] = new SpecialTransport<Passenger>(passenger, destination.c_str(), cost, true);
                else
                    passengerTransports[passengerSize++] = new Transport<Passenger>(passenger, destination.c_str(), cost);
            }
            cout << "Added!" << endl;
            break;
        }
        case 5:
            saveToFile(cargoTransports, cargoSize, passengerTransports, passengerSize);
            cout << "Data saved to file." << endl;
            break;
        case 0:
            cout << "Exit..." << endl;
            break;
        default:
            cout << "Wrong choice. Try again" << endl;
    }
} while (choice != 0);

    for (int i = 0; i < cargoSize; ++i) delete cargoTransports[i];
    for (int i = 0; i < passengerSize; ++i) delete passengerTransports[i];
    delete[] cargoTransports;
    delete[] passengerTransports;

    return 0;
}