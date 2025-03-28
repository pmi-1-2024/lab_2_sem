#include "MobilePhone.h"

bool compareByPrice(const MobilePhone& a, const MobilePhone& b) {
    return a.price < b.price;
}

bool compareByBrand(const MobilePhone& a, const MobilePhone& b) {
    return a.brand < b.brand;
}
