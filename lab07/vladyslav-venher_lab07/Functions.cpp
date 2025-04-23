#include <iostream>
#include <stdexcept>
#include "Functions.h"
#include "Transport.h"
#include "SpecialTransport.h"
using namespace std;

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

void showAllTransports(SpecialTransport<string> transports[], int count) {
    try {
        if (count <= 0) {
            throw out_of_range("No transports to show!");
        }
        cout << "\nAll transports:\n";
        for (int i = 0; i < count; ++i)
            cout << i + 1 << ". " << transports[i] << endl;
    }
    catch (const out_of_range& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

void showMostExpensiveTransport(SpecialTransport<string> transports[], int count) {
    try {
        if (count <= 0) {
            throw out_of_range("No transports available to find the most expensive one!");
        }
        int maxIndex = 0;
        for (int i = 1; i < count; ++i) {
            if (transports[i].getCost() > transports[maxIndex].getCost())
                maxIndex = i;
        }
        cout << "\nMost expensive transport:\n" << transports[maxIndex] << endl;
    }
    catch (const out_of_range& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

void updateTransport(SpecialTransport<string> transports[], int count) {
    try {
        int index;
        cout << "Enter transport index to update: ";
        cin >> index;
        if (index < 1 || index > count) {
            throw out_of_range("Invalid transport index!");
        }

        string newCargo, newDestination;
        cout << "Enter new cargo: ";
        cin >> newCargo;
        cout << "Enter new destination: ";
        cin >> newDestination;
        transports[index - 1].updateCargo(newCargo);
        transports[index - 1].updateDestination(newDestination);
        cout << "Updated transport:\n" << transports[index - 1] << endl;
    }
    catch (const out_of_range& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

void showDiscountedCosts(SpecialTransport<string> transports[], int count) {
    try {
        if (count <= 0) {
            throw out_of_range("No transports to show discounted costs!");
        }
        cout << "\nDiscounted transport costs:\n";
        for (int i = 0; i < count; ++i) {
            double discount = transports[i].calculateDiscount();
            double finalCost = transports[i].getCost() - discount;
            cout << i + 1 << ". " << transports[i]
                << ", discounted cost: " << finalCost << endl;
        }
    }
    catch (const out_of_range& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

void filterTransports(SpecialTransport<string> transports[], int count) {
    try {
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
        if (!found) {
            throw runtime_error("No transports found for the specified filter.");
        }
    }
    catch (const runtime_error& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

void showTotalCost(SpecialTransport<string> transports[], int count) {
    try {
        if (count <= 0) {
            throw out_of_range("No transports to calculate total cost!");
        }
        double total = 0.0;
        for (int i = 0; i < count; ++i)
            total += transports[i].getCost();
        cout << "Total cost of all transports: " << total << endl;
    }
    catch (const out_of_range& e) {
        cerr << "Error: " << e.what() << endl;
    }
}
