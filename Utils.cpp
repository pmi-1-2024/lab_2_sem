#include "utils.h"
#include "Logistics.h"
#include "PriorityLogistics.h"
#include "Traveler.h"
#include "Freight.h"
#include <iostream>
#include <string>

using namespace std;

#include "utils.h"
#include "Traveler.h"
#include "Freight.h"
#include "Logistics.h"
#include "PriorityLogistics.h"
#include "CustomException.h"
#include <iostream>
#include <fstream>

void LoadFromFile(ifstream& file, ILogistics** logistics_array, int& count) {
    string type;
    count = 0;

    while (file >> type && count < 8) {
        try {
            if (type == "Freight") {
                string name, origin;
                double mass, price;
                bool has_discount;

                file >> name >> mass >> origin >> price >> has_discount;
                if (!file) throw std::runtime_error("Incorrect data format for Freight");

                Freight freight(name, mass, origin);
                logistics_array[count++] = new Logistics<Freight>("Freight", freight, origin, price, has_discount);
            }
            else if (type == "Traveler") {
                string name, from, target, priority;
                int age;
                double price;
                bool has_discount;

                file >> name >> age >> from >> target >> price >> has_discount >> priority;
                if (!file) throw std::runtime_error("Incorrect data format for Traveler");

                Traveler passenger(name, age, from);
                logistics_array[count++] = new PriorityLogistics<Traveler>("Traveler", passenger, target, price, has_discount, priority);
            }
            else {
                throw CustomException("Unknown logistics type: " + type);
            }
        }
        catch (const exception& e) {
            cerr << "Error loading entry: " << e.what() << endl;
            file.clear();
            file.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

void ApplyDiscounts(ILogistics** logistics_array, int count) {
    for (int i = 0; i < count; ++i) {
        double discounted = logistics_array[i]->FinalPrice();
        logistics_array[i]->SetPrice(discounted);
    }
}

double TotalPrice(ILogistics** logistics_array, int count) {
    double total = 0.0;
    for (int i = 0; i < count; ++i) {
        total += logistics_array[i]->FinalPrice();
    }
    return total;
}

int FindMostExpensive(ILogistics** logistics_array, int count) {
    if (count == 0) return -1;

    int max_index = 0;
    double max_price = logistics_array[0]->FinalPrice();

    for (int i = 1; i < count; ++i) {
        double price = logistics_array[i]->FinalPrice();
        if (price > max_price) {
            max_price = price;
            max_index = i;
        }
    }
    return max_index;
}

void ShowMenu() {
    cout << "=== Logistics Menu ===\n";
    cout << "1. Load data from file\n";
    cout << "2. Show all records\n";
    cout << "3. Apply discounts\n";
    cout << "4. Show total price\n";
    cout << "5. Show most expensive\n";
    cout << "0. Exit\n";
    cout << "Choose an option: ";
}

void HandleMenuChoice(ILogistics** logistics_array, int& count, int choice, int& discount_applied) {
    switch (choice) {
    case 1:
        cout << "Loading from file is not implemented here.\n";
        break;
    case 2:
        for (int i = 0; i < count; ++i)
            cout << *logistics_array[i] << endl;
        break;
    case 3:
        ApplyDiscounts(logistics_array, count);
        cout << "Discounts applied.\n";
        ++discount_applied;
        break;
    case 4:
        cout << "Total price: " << TotalPrice(logistics_array, count) << endl;
        break;
    case 5: {
        int max_index = FindMostExpensive(logistics_array, count);
        if (max_index >= 0)
            cout << "Most expensive:\n" << *logistics_array[max_index] << endl;
        else
            cout << "No data available.\n";
        break;
    }
    case 0:
        cout << "Exiting...\n";
        break;
    default:
        cout << "Invalid option. Try again.\n";
        break;
    }
}
