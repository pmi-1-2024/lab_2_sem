#include <bits/stdc++.h>
#include "../head/add.h"
using namespace std;

void adres::inp()
{
    in >> zip >> city >> str;
}
void adres::out()
{
    cout << "addres: ";
    cout << zip << " " << city << ' ' << str << endl;
}

adres::adres(){
    zip = 0, city = "", str = "";
}

adres::adres(int zp, string ct, string st)
{
    zip = zip, city = ct, str = st;
}


