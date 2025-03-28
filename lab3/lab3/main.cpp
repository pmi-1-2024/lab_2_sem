// lab3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Phone.h"
#include "MobilePhone.h"
#include "RadioPhone.h"
#include "PhoneFactory.h"
#include "MegaPhone.h"
#include <iostream>
#include <fstream>


using namespace std;


Phone* createPhone(istream& in) {
    int type;
    if (!(in >> type)) {
        //cerr << "Failed to read phone type.\n";
        return nullptr;
    }

    string name, brand;
    double price;
    if (!(in >> name >> brand >> price)) {
        cerr << "Failed to read phone data.\n";
        return nullptr;
    }

    if (type == 2) {
        string color;
        int memory;
        if (!(in >> color >> memory)) {
            cerr << "Failed to read mobile phone details.\n";
            return nullptr;
        }
        return new MobilePhone(name, brand, price, color, memory);
    }
    else if (type == 3) {
        double range;
        bool answeringMachine;
        if (!(in >> range >> answeringMachine)) {
            cerr << "Failed to read radio phone details.\n";
            return nullptr;
        }
        return new RadioPhone(name, brand, price, range, answeringMachine);
    }
    else if (type == 4) {
        string color;
        int memory;
        double range;
        bool answeringMachine;
        if (!(in >> color >> memory >> range >> answeringMachine)) {
            cerr << "Failed to read mega phone details.\n";
            return nullptr;
        }
        return new MegaPhone(name, brand, price, color, memory, range, answeringMachine);
    }
    else {
        cerr << "Unknown phone type: " << type << endl;
        return nullptr;
    }
}

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

    while (count < MAX_SIZE && file1 >> phones[count]) {
        if (!phones[count]) {
            cerr << "Error reading phone from file1!" << endl;
            break;
        }
        count++;
    }

    while (count < MAX_SIZE) {
        phones[count] = createPhone(file1);
        if (phones[count] == nullptr) break;
        ++count;
    }


    while (count < MAX_SIZE) {
        phones[count] = createPhone(file2);
        if (phones[count] == nullptr) break;
        ++count;
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

    cout << "\nMega phones:\n";
    output << "\nMega phones:\n";
    for (int i = 0; i < count; ++i) {
        MegaPhone* mp = dynamic_cast<MegaPhone*>(phones[i]);
        if (mp) {
            mp->display();
        }
    }

    cout << "Total price: " << totalPrice << "\n";
    output << "Total price: " << totalPrice << "\n";


    cout << "\nRadio phones with answering machine:\n";
    output << "\nRadio phones with answering machine:\n";
    for (int i = 0; i < count; ++i) {
        if (phones[i] && phones[i]->hasAnsweringMachine()) {
            phones[i]->display();
        }
    }

    for (int i = 0; i < count; ++i) delete phones[i];

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
