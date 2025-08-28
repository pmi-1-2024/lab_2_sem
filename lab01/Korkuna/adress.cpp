#include "adress.h"

ostream& operator << (ostream& out, const Adress& a)
{
    out << "Zip:" << a.zip << " City:" << a.city << " Street:" << a.street;
    return out;
}

istream& operator >> (istream& in, Adress& a)
{
    cout << "Zip: ";
    in >> a.zip;
    cout << "City: ";
    in >> a.city;
    cout << "Street: ";
    in >> a.street;
    cout << "__________" << endl;
    return in;
}

string Adress::get_zip() {
    return zip;
}