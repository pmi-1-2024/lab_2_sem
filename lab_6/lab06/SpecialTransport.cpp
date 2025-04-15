#include "SpecialTransport.h"
#include <cstring>

template<typename T>
SpecialTransport<T>::SpecialTransport(T cargo, const char* destination, double cost, bool special)
    : Transport<T>(cargo, destination, cost), hasSpecialConditions(special) {}

template<typename T>
double SpecialTransport<T>::calculateDiscount(double percent) const {
    double discount = Transport<T>::calculateDiscount(percent);
    return hasSpecialConditions ? discount - 50 : discount;
}

template<typename T>
void SpecialTransport<T>::print() const {
    Transport<T>::print();
    if (hasSpecialConditions)
        cout << "Special conditions: Yes (additional discount of 50 UAH)" << endl;
    else
        cout << "Special conditions: None" << endl;
}

template class SpecialTransport<string>;