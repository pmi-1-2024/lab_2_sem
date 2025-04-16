#include <iostream>
#include <fstream>
#include "SpecialTransport.h"
using namespace std;

const int MAX_TRANSPORTS = 100;

void showMenu() {
    cout << "\n===== Transport Management System =====\n";
    cout << "1. Show all transports\n";
    cout << "2. Show most expensive transport\n";
    cout << "3. Update cargo and destination\n";
    cout << "4. Show discounted costs\n";
    cout << "5. Filter transports by type\n";
    cout << "6. Show total cost of all transports\n";
    cout << "0. Exit\n";
    cout << "Choose an option: ";
}

int main() {
    SpecialTransport<string> transports[MAX_TRANSPORTS];
    int count = 0;

    ifstream inFile("data.txt");
    if (!inFile) {
        cerr << "Error: File could not be opened!" << endl;
        return 1;
    }

    while (count < MAX_TRANSPORTS && inFile >> transports[count]) {
        count++;
    }
    inFile.close();

    int option;
    do {
        showMenu();
        cin >> option;

        switch (option) {
        case 1: {
            cout << "\nAll transports:\n";
            for (int i = 0; i < count; ++i)
                cout << i + 1 << ". " << transports[i] << endl;
            break;
        }
        case 2: {
            int maxIndex = 0;
            for (int i = 1; i < count; ++i) {
                if (transports[i].getCost() > transports[maxIndex].getCost())
                    maxIndex = i;
            }
            cout << "\nMost expensive transport:\n" << transports[maxIndex] << endl;
            break;
        }
        case 3: {
            int index;
            cout << "Enter transport index to update: ";
            cin >> index;
            if (index >= 1 && index <= count) {
                string newCargo, newDestination;
                cout << "Enter new cargo: ";
                cin >> newCargo;
                cout << "Enter new destination: ";
                cin >> newDestination;
                transports[index - 1].updateCargo(newCargo);
                transports[index - 1].updateDestination(newDestination);
                cout << "Updated transport:\n" << transports[index - 1] << endl;
            }
            else {
                cout << "Invalid index!" << endl;
            }
            break;
        }
        case 4: {
            cout << "\nDiscounted transport costs:\n";
            for (int i = 0; i < count; ++i) {
                double discount = transports[i].calculateDiscount();
                double finalCost = transports[i].getCost() - discount;
                cout << i + 1 << ". " << transports[i]
                    << ", discounted cost: " << finalCost << endl;
            }
            break;
        }
        case 5: {
            string filterType;
            cout << "Enter cargo type to filter (passenger/cargo/all): ";
            cin >> filterType;
            bool found = false;
            for (int i = 0; i < count; ++i) {
                if (filterType == "all" || transports[i].getCargoType() == filterType) {
                    cout << i + 1 << ". " << transports[i] << endl;
                    found = true;
                }
            }
            if (!found) cout << "No transports found.\n";
            break;
        }
        case 6: {
            double total = 0.0;
            for (int i = 0; i < count; ++i)
                total += transports[i].getCost();
            cout << "Total cost of all transports: " << total << endl;
            break;
        }
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid option!\n";
        }

    } while (option != 0);

    return 0;
}
