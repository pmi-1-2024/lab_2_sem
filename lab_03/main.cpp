#include "Phone.h"
#include "MobilePhone.h"
#include "RadioPhone.h"
#include "HybridPhone.h"
#include <fstream>
#include <iostream>
using namespace std;

// Пошук по назві
bool matchesByName(Phone* phone, const string& name) {
    return phone->getName() == name;
}

// Пошук по бренду
bool matchesByBrand(Phone* phone, const string& brand) {
    return phone->getBrand() == brand;
}

// Пошук по ціні
bool matchesByPrice(Phone* phone, double maxPrice) {
    return phone->getPrice() <= maxPrice;
}

int main() {
    ifstream file1("phones1.txt");
    ifstream file2("phones2.txt");

    if (!file1 || !file2) {
        cerr << "Error opening input files!" << endl;
        return 1;
    }

    int size = 0;
    Phone** phones = new Phone * [100];
    int type;

    // Зчитування з файлів
    while (file1 >> type) {
        if (type == 1) phones[size] = new MobilePhone;
        else if (type == 2) phones[size] = new RadioPhone;
        else if (type == 3) phones[size] = new HybridPhone;
        file1 >> *phones[size];
        size++;
    }

    while (file2 >> type) {
        if (type == 1) phones[size] = new MobilePhone;
        else if (type == 2) phones[size] = new RadioPhone;
        else if (type == 3) phones[size] = new HybridPhone;
        file2 >> *phones[size];
        size++;
    }

    // Меню вибору пошуку
    int choice;
    cout << "Search by:\n1. Name\n2. Brand\n3. Price\nEnter choice (1-3): ";
    cin >> choice;

    ofstream output("res.txt");
    if (!output) {
        cerr << "Error opening output file!" << endl;
        return 1;
    }

    if (choice == 1) {
        string name;
        cout << "Enter name to search: ";
        cin >> name;
        for (int i = 0; i < size; i++) {
            if (matchesByName(phones[i], name)) {
                output << *phones[i];
            }
        }
    }
    else if (choice == 2) {
        string brand;
        cout << "Enter brand to search: ";
        cin >> brand;
        for (int i = 0; i < size; i++) {
            if (matchesByBrand(phones[i], brand)) {
                output << *phones[i];
            }
        }
    }
    else if (choice == 3) {
        double price;
        cout << "Enter maximum price: ";
        cin >> price;
        for (int i = 0; i < size; i++) {
            if (matchesByPrice(phones[i], price)) {
                output << *phones[i];
            }
        }
    }
    else {
        cout << "Invalid choice!" << endl;
    }

    // Очищення пам’яті
    for (int i = 0; i < size; i++) {
        delete phones[i];
    }
    delete[] phones;

    return 0;
}
