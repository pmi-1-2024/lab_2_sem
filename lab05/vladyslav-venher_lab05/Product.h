#ifndef PRODUCT_H
#define PRODUCT_H
#include <iostream>
#include <string>
using namespace std;

struct Product {
    string name;  
    double price; 
    int quantity;

    Product();
    bool operator>(const Product& product) const;
    bool operator<(const Product& product) const;
    friend ostream& operator<<(ostream& os, const Product& product);
    friend istream& operator>>(istream& is, Product& product);
};

#endif
