#include "Address_Manager.h"
#include <iostream>

using namespace std;

void Address_Manager::menu() {
    int choice;
    do {
        cout << "Menu:" << endl
            << "1. Add address" << endl
            << "2. Remove address" << endl
            << "3. Find address" << endl
            << "4. Replace address" << endl
            << "5. Display all addresses" << endl
            << "0. Exit" << endl
            << "Your choice: ";
        cin >> choice;

        string index, city, street;
        Address address;

        switch (choice) {
        case 1:
            cout << "Enter index, city, street: " << endl;
            cin >> index >> city >> street;
            addAddress(Address(index, city, street));
            break;
        case 2:
            cout << "Enter index, city, street of the address to remove: " << endl;
            cin >> index >> city >> street;
            removeAddress(Address(index, city, street));
            break;
        case 3:
            cout << "Enter index, city, street to find: " << endl;
            cin >> index >> city >> street;
            if (findAddress(Address(index, city, street))) {
                cout << "Address found!" << endl;
            }
            else {
                cout << "Address not found." << endl;
            }
            break;
        case 4:
            cout << "Enter old address (index, city, street): " << endl;
            cin >> index >> city >> street;
            address = Address(index, city, street);
            cout << "Enter new address (index, city, street): " << endl;
            cin >> index >> city >> street;
            replaceAddress(address, Address(index, city, street));
            break;
        case 5:
            displayAllAddresses();
            break;
        case 0:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 0);
}

void Address_Manager::addAddress(const Address& a) {
    address_list.push(a);
}

void Address_Manager::removeAddress(const Address& a) {
    Address_link* node = address_list.find(a);
    if (node) {
        address_list.remove(node);
        delete node;
    }
}

Address_link* Address_Manager::findAddress(const Address& a) {
    return address_list.find(a);
}

void Address_Manager::replaceAddress(const Address& oldAddr, const Address& newAddr) {
    Address_link* node = address_list.find(oldAddr);
    if (node) {
        node->data = newAddr;
    }
}

void Address_Manager::displayAllAddresses() const {
    Address_link* temp = address_list.top();
    while (temp) {
        cout << temp->data;
        temp = (Address_link*)temp->next;
    }
}

