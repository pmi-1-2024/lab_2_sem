#include "Address.h"

Address::Address(int postIndex, string city, string street)
    : postIndex(postIndex), city(city), street(street) {}

int Address::getPostIndex() const { return postIndex; }
string Address::getCity() const { return city; }
string Address::getStreet() const { return street; }


