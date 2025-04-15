#include "Transport.h"
#include "SpecialTransport.h"
#include <fstream>

const int INITIAL_SIZE = 10;

static void resizeArray(Transport<string>**& arr, int& capacity) {
    int newCap = capacity * 2;
    Transport<string>** newArr = new Transport<string>*[newCap];
    for (int i = 0; i < capacity; ++i) {
        newArr[i] = arr[i];
    }
    delete[] arr;
    arr = newArr;
    capacity = newCap;
}

static void saveToFile(Transport<string>** arr, int size) {
    ofstream fout("Text.txt");
    if (!fout.is_open()) {
        cerr << "Error opening a file for writing.\n";
        return;
    }
    for (int i = 0; i < size; ++i) {
        if (arr[i] == nullptr)
            continue; 

        SpecialTransport<string>* st = dynamic_cast<SpecialTransport<string>*>(arr[i]);
        fout << arr[i]->getCargo() << " "
            << arr[i]->getDestination() << " "
            << arr[i]->getCost() << " "
            << (st ? 1 : 0) << endl;
    }
    fout.close();
}

int main() {
    ifstream file("Text.txt");
    if (!file) {
        cout << "Could not open Text.txt" << endl;
        return 1;
    }

    int capacity = INITIAL_SIZE;
    int size = 0;
    Transport<string>** transports = new Transport<string>*[capacity];

    string cargo, destination;
    double cost;
    bool special;

    while (file >> cargo >> destination >> cost >> special) {
        if (size >= capacity) resizeArray(transports, capacity);

        if (special)
            transports[size++] = new SpecialTransport<string>(cargo, destination.c_str(), cost, true);
        else
            transports[size++] = new Transport<string>(cargo, destination.c_str(), cost);
    }
    file.close();

    int choice;
    do {
        cout << "========MENU================" << endl;
        cout << "1. Show all transportations" << endl;
        cout << "2. Show discounts (10%)" << endl;
        cout << "3. Add new transportation" << endl;
        cout << "4. Save to file" << endl;
        cout << "0. Exit" << endl;
        cout << "============================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            for (int i = 0; i < size; ++i) {
                cout << "\nTransportation #" << i + 1 << ":\n";
                transports[i]->print();
            }
            break;
        case 2:
            for (int i = 0; i < size; ++i) {
                cout << "With a 10% discount: " << transports[i]->calculateDiscount(10) << " UAH\n";
            }
            break;
        case 3: {
            string newCargo, newDestination;
            double newCost;
            bool isSpecial;

            cout << "Enter the cargo: ";
            cin >> newCargo;
            cout << "Enter the destination: ";
            cin >> newDestination;
            cout << "Enter the cost: ";
            cin >> newCost;
            cout << "Are there any special conditions (1 - yes, 0 - no): ";
            cin >> isSpecial;

            if (size >= capacity) resizeArray(transports, capacity);

            if (isSpecial)
                transports[size++] = new SpecialTransport<string>(newCargo, newDestination.c_str(), newCost, true);
            else
                transports[size++] = new Transport<string>(newCargo, newDestination.c_str(), newCost);

            cout << "New transportation added!\n";
            break;
        }
        case 4:
            saveToFile(transports, size);
            cout << "Data saved to file.\n";
            break;
        case 0:
            cout << "Completion of the program...\n";
            break;
        default:
            cout << "Wrong choice. Please try again.\n";
        }

    } while (choice != 0);

    for (int i = 0; i < size; ++i)
        delete transports[i];
    delete[] transports;

    return 0;
}