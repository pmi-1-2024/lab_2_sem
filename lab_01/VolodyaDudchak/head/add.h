#include <bits/stdc++.h>

using namespace std;

class adres{
    private:
    int zip;
    string city;
    string str;
    public:
    adres();
    adres(int zp, string ct, string st);
    int getZip();
    string getCity();
    string getStr();
    friend ostream& operator <<(ostream& out, adres& a);
    friend istream& operator >>(istream& out, adres& a);
};