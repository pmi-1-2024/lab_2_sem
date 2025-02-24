#include <bits/stdc++.h>
#include "../head/stud.h"
using namespace std;

student::student(){
    name = "", ad = adres(), group = 0, zali = zalikov();
}
student::student(string ne, int gp, adres add, zalikov zi)
{
    name = ne, ad = add, group = gp, zali = zi;
}
void student::inp()
{
    in >> name >> group;
    zali.inp();
    ad.inp();
}
void student::out()
{
    cout << "student: ";
    cout << name << ' ' << group;
    cout << endl;
    zali.out();
    ad.out();
}


zalikov student::getZali(){
    return zali;
}
string student:: getName(){
    return name;
}

adres student::getAd(){
    return ad;
}

int student:: getGroup(){
    return group;
}