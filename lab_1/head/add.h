#include <bits/stdc++.h>
using namespace std;

class adres{
    public:
    int zip;
    string city;
    string str;
    adres(){
        zip = 0, city = "", str = "";
    }
    adres(int zp, string ct, string st)
    {
        zip = zip, city = ct, str = st;
    }
    void inp()
    {
        in >> zip >> city >> str;
    }
    void out()
    {
        cout << "addres: ";
        cout << zip << " " << city << ' ' << str << endl;
    }
};