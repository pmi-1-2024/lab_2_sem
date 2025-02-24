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
    void inp();
    void out();
    int getZip();
    string getCity();
    string getStr();
};