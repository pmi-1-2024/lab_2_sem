#ifndef SPECIAL_TRANSPORT_CPP
#define SPECIAL_TRANSPORT_CPP

#include "special_transport.h"
#include "transport_exception.h"

template <typename T>
SpecialTransport<T>::SpecialTransport()
    : Transport<T>(), condition("normal") {}

template <typename T>
SpecialTransport<T>::SpecialTransport(T c, string d, double cost, string cond)
    : Transport<T>(c, d, cost), condition(cond) {
    if (cond.empty()) {
        throw TransportException("����� ����������� �� ���� ���� ���������");
    }
}

template <typename T>
double SpecialTransport<T>::calculateDiscountedCost() const {
    if (condition == "medical" || condition == "special") {
        return this->cost * 0.8;
    }
    return this->cost;
}

template <typename T>
void SpecialTransport<T>::print() const {
    cout << "��������������� � ������: " << this->cargo
        << ", ����� �����������: " << this->destination
        << ", �������: " << this->cost
        << ", �����: " << condition << endl;
}

template <typename T>
string SpecialTransport<T>::getCondition() const {
    return condition;
}

#endif 