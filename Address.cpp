#include "Address.h"

ostream& operator<<(ostream& out, const Address& addr) {
    out << "������: " << addr.city << ", " << addr.street << " (ZIP: " << addr.zipCode << ")";
    return out;
}

istream& operator>>(istream& in, Address& addr) {
    cout << "������ ����: ";
    in >> addr.city;
    cout << "������ ������: ";
    in >> addr.street;
    cout << "������ ZIP ���: ";
    in >> addr.zipCode;
    return in;
}
