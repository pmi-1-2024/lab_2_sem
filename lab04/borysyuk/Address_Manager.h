#pragma once
#include "Address_List.h"
#include <iostream>

class Address_Manager {
private:
    Address_list address_list;

public:
    void menu();
    void addAddress(const Address& a);
    void removeAddress(const Address& a);
    Address_link* findAddress(const Address& a);
    void replaceAddress(const Address& oldAddr, const Address& newAddr);
    void displayAllAddresses() const;
};

