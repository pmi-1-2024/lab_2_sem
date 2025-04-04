#include "Phone.h"
Phone::Phone(string name, string brand, double price) : name(name), brand(brand), price(price) {}
ostream& operator<<(ostream& os, const Phone& p) {
    p.print(os);
    return os;
}
istream& operator>>(istream& is, Phone& p) {
    p.read(is);
    return is;
}