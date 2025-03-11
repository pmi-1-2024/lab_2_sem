#include "Address.h"

ostream& operator<<(ostream& out, const Address& addr) {
    out << "Àäğåñà: " << addr.city << ", " << addr.street << " (ZIP: " << addr.zipCode << ")";
    return out;
}

istream& operator>>(istream& in, Address& addr) {
    cout << "Ââåä³òü ì³ñòî: ";
    in >> addr.city;
    cout << "Ââåä³òü âóëèöş: ";
    in >> addr.street;
    cout << "Ââåä³òü ZIP êîä: ";
    in >> addr.zipCode;
    return in;
}
