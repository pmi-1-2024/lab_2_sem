#include <bits/stdc++.h>
#include "zal.h"
#include "add.h"
using namespace std;


class student{
    public:
    string name;
    adres ad;
    int group;
    zalikov zali;
    student(){
        name = "", ad = adres(), group = 0, zali = zalikov();
    }
    student(string ne, int gp, adres add, zalikov zi)
    {
        name = ne, ad = add, group = gp, zali = zi;
    }
    void inp()
    {
        in >> name >> group;
        zali.inp();
        ad.inp();
    }
    void out()
    {
        cout << "student: ";
        cout << name << ' ' << group;
        cout << endl;
        zali.out();
        ad.out();
    }
};