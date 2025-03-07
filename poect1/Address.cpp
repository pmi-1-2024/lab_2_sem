#include "Address.h"

using namespace std;

ostream& operator<<(ostream& os, const Adress& adr) {
    os << adr.postIndex << ", " << adr.city << ", " << adr.street;
    return os;
}

istream& operator>>(istream& is, Adress& adr) {
    is >> adr.postIndex >> adr.city >> adr.street;
    return is;
}

