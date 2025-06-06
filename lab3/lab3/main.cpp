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



int main() {
    ifstream file1("phones1.txt"), file2("phones2.txt");
    ofstream output("result.txt");

    if (!file1 || !file2) {
        cerr << "Error opening files!" << endl;
        return 1;
    }

   /* const int MAX_SIZE = 100;
    Phone* phones[MAX_SIZE];
    int count = 0;*/

    while (count < MAX_SIZE && file1 >> phones[count]) {
        if (!phones[count]) {
            cerr << "Error reading phone from file1!" << endl;
            break;
        }
        count++;
    }

   /* while (count < MAX_SIZE) {
        phones[count] = createPhone(file1);
        if (phones[count] == nullptr) break;
        ++count;
    }


    while (count < MAX_SIZE) {
        phones[count] = createPhone(file2);
        if (phones[count] == nullptr) break;
        ++count;
    }*/

    int size = 0;
    Phone** phones = new Phone * [100];
    int type;

    while (file1 >> type) {
        if (type == 1)
            phones[size] = new MobilePhone;
        else if (type == 2)
            phones[size] = new RadioPhone;
        else if (type == 3)
            phones[size] = new MegaPhone;
        else
            continue;

        file1 >> *phones[size];
        size++;
    }

    while (file2 >> type) {
        if (type == 1)
            phones[size] = new MobilePhone;
        else if (type == 2)
            phones[size] = new RadioPhone;
        else if (type == 3)
            phones[size] = new MegaPhone;
        else
            continue;

        file2 >> *phones[size];
        size++;
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
