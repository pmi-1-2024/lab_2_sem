// llab_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Phone.h"
#include "MobilePhone.h"
#include "RadioPhone.h"
#include "PhoneFactory.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;



int main() {
    ifstream file1("phones1.txt"), file2("phones2.txt");
    ofstream output("result.txt");

    if (!file1 || !file2) {
        cerr << "Error opening files!" << endl;
        return 1;
    }

    const int MAX_SIZE = 100;
    Phone* phones[MAX_SIZE];
    int count = 0;

    while (count < MAX_SIZE) {
        Phone* temp = nullptr;
        if (file1 >> temp && temp) {
            phones[count++] = temp;
        }
        else {
            break;
        }
    }

    while (count < MAX_SIZE) {
        Phone* temp = nullptr;
        if (file2 >> temp && temp) {
            phones[count++] = temp;
        }
        else {
            break;
        }
    }

    cout << "Loaded phones: " << count << endl;
    if (count == 0) {
        cerr << "No valid data read from files." << endl;
        return 1;
    }

    for (int i = 0; i < count - 1; ++i) {
        for (int j = i + 1; j < count; ++j) {
            if (*phones[j] < *phones[i]) {
                swap(phones[i], phones[j]);
            }
        }
    }

    double totalPrice = 0.0;
    cout << "All phones sorted by price:\n";
    output << "All phones sorted by price:\n";

    for (int i = 0; i < count; ++i) {
        if (phones[i]) {
            phones[i]->display(); 
            output << phones[i]->getPrice() << "\n";
            totalPrice += phones[i]->getPrice();
        }
    }

    cout << "Total price: " << totalPrice << "\n";
    output << "Total price: " << totalPrice << "\n";


    cout << "\nRadio phones with answering machine:\n";
    output << "\nRadio phones with answering machine:\n";

    for (int i = 0; i < count; ++i) {
        if (phones[i] && phones[i]->hasAnsweringMachine()) {
            phones[i]->display();
            output << phones[i]->getPrice() << "\n";
        }
    }

    for (int i = 0; i < count; ++i) {
        delete phones[i];
    }

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
