#include "Product.h"

Product::Product() : name(" "), price(0.0), quantity(0) {}

bool Product::operator>(const Product& product) const {
    if (price != product.price) return price > product.price;
    if (name != product.name) return name > product.name;
    return quantity > product.quantity;
}

bool Product::operator<(const Product& product) const {
    if (price != product.price) return price < product.price;
    if (name != product.name) return name < product.name;
    return quantity < product.quantity;
}

ostream& operator<<(ostream& os, const Product& product) {
    os << "Name: " << product.name
        << ", Price: " << product.price
        << ", Quantity: " << product.quantity;
    return os;
}

istream& operator>>(istream& is, Product& product) {
    cout << "Enter product name: ";
    is >> product.name;
    cout << "Enter product price: ";
    is >> product.price;
    while (product.price < 0) { 
        cout << "Invalid price. Enter a positive value: ";
        is >> product.price;
    }
    cout << "Enter product quantity: ";
    is >> product.quantity;
    while (product.quantity < 0) {
        cout << "Invalid quantity. Enter a positive value: ";
        is >> product.quantity;
    }
    is.ignore();
    return is;
}
