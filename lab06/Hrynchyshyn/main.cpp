#include <iostream>
#include <fstream>
#include <string>
#include "Transport.h"
#include "SpecialTransport.h"
#include "CargoTypes.h"
#include <sstream>

using namespace std;

template <typename T>
int findMostExpensive(Transport<T>** transports, int size) {
    if (size == 0) {
        return -1; 
    }
    int maxIndex = 0;
    for (int i = 1; i < size; ++i) {
        if (transports[i]->getCost() > transports[maxIndex]->getCost()) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

template <typename T>
void applyDiscount(Transport<T>& transport) {
    transport.setCost(transport.getCost() - transport.calculateDiscount());
}

template <typename T>
int filterByType(Transport<T>** transports, int size, T type, Transport<T>** filteredArray, int& filteredSize) {
    filteredSize = 0;
    for (int i = 0; i < size; ++i) {
        if (transports[i]->getCargo() == type) {
            filteredArray[filteredSize++] = transports[i];
        }
    }
    return filteredSize;
}

template <typename T>
double calculateTotalCost(Transport<T>** transports, int size) {
    double totalCost = 0.0;
    for (int i = 0; i < size; ++i) {
        totalCost += transports[i]->getCost();
    }
    return totalCost;
}

template <typename T>
void saveDataToFile(Transport<T>** transports, int size, const char* filename) {
    ofstream file(filename);
    if (file.is_open()) {
        file << size << endl; 
        for (int i = 0; i < size; ++i) {
            SpecialTransport<T>* specialPtr = dynamic_cast<SpecialTransport<T>*>(transports[i]);
            if (specialPtr) {
                file << "SpecialTransport" << endl;
                file << specialPtr->getCargo() << endl;
                file << specialPtr->getDestination() << endl;
                file << specialPtr->getCost() << endl;
                file << specialPtr->getSpecialConditions() << endl;
            }
            else {
                file << "Transport" << endl;
                file << transports[i]->getCargo() << endl;
                file << transports[i]->getDestination() << endl;
                file << transports[i]->getCost() << endl;
            }
        }
        file.close();
        cout << "Data successfully written to file " << filename << endl;
    }
    else {
        cerr << "Unable to open file for writing." << endl;
    }
}

template <typename T>
Transport<T>** loadDataFromFile(const char* filename, int& size) {
    ifstream file(filename);
    if (file.is_open()) {
        file >> size;
        file.ignore(); 
        Transport<T>** transports = new Transport<T>*[size];
        for (int i = 0; i < size; ++i) {
            string type;
            getline(file, type);
            if (type == "SpecialTransport") {
                T cargo;
                string destination;
                double cost;
                string specialConditions;
                file >> cargo;
                file.ignore();
                getline(file, destination);
                file >> cost;
                file.ignore();
                getline(file, specialConditions);
                transports[i] = new SpecialTransport<T>(cargo, destination, cost, specialConditions);
            }
            else if (type == "Transport") {
                T cargo;
                string destination;
                double cost;
                file >> cargo;
                file.ignore();
                getline(file, destination);
                file >> cost;
                file.ignore();
                transports[i] = new Transport<T>();
                transports[i]->setCargo(cargo);
                transports[i]->setDestination(destination);
                transports[i]->setCost(cost);
            }
            else {
                cerr << "Unknown transport type in file." << endl;
                delete[] transports;
                size = 0;
                return nullptr;
            }
        }
        file.close();
        cout << "Data successfully loaded from file " << filename << endl;
        return transports;
    }
    else {
        cerr << "Unable to open file for reading." << endl;
        size = 0;
        return nullptr;
    }
}

int main() {
    int capacity = 10;
    Transport<string>** transports = new Transport<string>*[capacity];
    int size = 0;
    const char* filename = "data.txt";

    transports = loadDataFromFile<string>(filename, size); 
    if (size > capacity) {
        capacity = size * 2;
        Transport<string>** newTransports = new Transport<string>*[capacity];
        for (int i = 0; i < size; ++i) {
            newTransports[i] = transports[i];
        }
        delete[] transports;
        transports = newTransports;
    }

    int choice;
    do {
        cout << "\nTransportation Management Menu:" << endl;
        cout << "1. Add Order" << endl;
        cout << "2. Find Most Expensive Offer" << endl;
        cout << "3. Apply Discount" << endl;
        cout << "4. Search by Type: Passenger or Freight" << endl;
        cout << "5. Calculate Total Cost of Transportations" << endl;
        cout << "6. Set Destination for Transportation" << endl;
        cout << "7. Update Cargo and Destination for Transportation" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: {
            if (size < capacity) {
                cout << "Enter transportation type (regular/special): ";
                string type;
                getline(cin, type);
                if (type == "regular") {
                    transports[size] = new Transport<string>();
                    cin >> *transports[size];
                    size++;
                }
                else if (type == "special") {
                    transports[size] = new SpecialTransport<string>();
                    cin >> static_cast<SpecialTransport<string>&>(*transports[size]);
                    size++;
                }
                else {
                    cout << "Invalid transportation type." << endl;
                }
            }
            else {
                cout << "Maximum number of orders reached." << endl;
            }
            break;
        }
        case 2: {
            int index = findMostExpensive(transports, size);
            if (index != -1) {
                cout << "\nMost Expensive Transportation:" << endl;
                transports[index]->displayInfo();
            }
            else {
                cout << "No transportations available." << endl;
            }
            break;
        }
        case 3: {
            if (size > 0) {
                cout << "Enter the index of the transportation to apply discount (0 - " << size - 1 << "): ";
                int index;
                cin >> index;
                if (index >= 0 && index < size) {
                    applyDiscount(*transports[index]);
                    cout << "Discount applied. New cost: " << fixed << transports[index]->getCost() << endl;
                }
                else {
                    cout << "Invalid index." << endl;
                }
            }
            else {
                cout << "No transportations available." << endl;
            }
            break;
        }
        case 4: {
            cout << "Enter the cargo type to search for: ";
            string searchType;
            getline(cin, searchType);
            Transport<string>** filtered = new Transport<string>*[size];
            int filteredSize;
            filterByType(transports, size, searchType, filtered, filteredSize);
            if (filteredSize > 0) {
                cout << "\nTransportations with cargo type '" << searchType << "':" << endl;
                for (int i = 0; i < filteredSize; ++i) {
                    filtered[i]->displayInfo();
                    cout << "---" << endl;
                }
            }
            else {
                cout << "No transportations found with this cargo type." << endl;
            }
            delete[] filtered;
            break;
        }
        case 5: {
            double totalCost = calculateTotalCost(transports, size);
            cout << "Total cost of all transportations: " << fixed << totalCost << endl;
            break;
        }
        case 6: {
            if (size > 0) {
                cout << "Enter the index of the transportation to update the destination (0 - " << size - 1 << "): ";
                int index;
                cin >> index;
                cin.ignore();
                if (index >= 0 && index < size) {
                    cout << "Enter the new destination: ";
                    string newDestination;
                    getline(cin, newDestination);
                    transports[index]->setDestination(newDestination);
                    cout << "Destination updated." << endl;
                }
                else {
                    cout << "Invalid index." << endl;
                }
            }
            else {
                cout << "No transportations available." << endl;
            }
            break;
        }
        case 7: {
            if (size > 0) {
                cout << "Enter the index of the transportation to update cargo and destination (0 - " << size - 1 << "): ";
                int index;
                cin >> index;
                cin.ignore();
                if (index >= 0 && index < size) {
                    cout << "Enter the new cargo: ";
                    string newCargo;
                    getline(cin, newCargo);
                    transports[index]->setCargo(newCargo);
                    cout << "Enter the new destination: ";
                    string newDestination;
                    getline(cin, newDestination);
                    transports[index]->setDestination(newDestination);
                    cout << "Cargo and destination updated." << endl;
                }
                else {
                    cout << "Invalid index." << endl;
                }
            }
            else {
                cout << "No transportations available." << endl;
            }
            break;
        }
        case 8: {
            cout << "Exiting the program." << endl;
            break;
        }
        default: {
            cout << "Invalid choice. Please try again." << endl;
        }
        }
    } while (choice != 8);

    saveDataToFile(transports, size, filename);

    for (int i = 0; i < size; ++i) {
        delete transports[i];
    }
    delete[] transports;

    return 0;
}