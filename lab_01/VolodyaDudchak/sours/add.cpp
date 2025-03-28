#include <bits/stdc++.h>
#include "../head/add.h"
using namespace std;

adres::adres(){
    zip = 0, city = "", str = "";
}

adres::adres(int zp, string ct, string st)
{
    zip = zip, city = ct, str = st;
}

int adres::getZip(){
    return zip;
}

string adres::getStr(){
    return str;
}

string adres::getCity(){
    return city;
}

istream& operator >> (istream& in, adres& a){
    in >> a.zip >> a.city >> a.str;
    return in;
}
ostream& operator << (ostream& out, adres& a){
    out << "addres: ";
    out << a.zip << " " << a.city << ' ' << a.str << endl;
    return out;
}