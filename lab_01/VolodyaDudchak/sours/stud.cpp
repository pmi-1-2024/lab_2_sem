#include <bits/stdc++.h>
#include "../head/stud.h"
using namespace std;

student::student(){
    name = "", ad = adres(), group = 0;
}
student::student(string ne, int gp, adres add, zalikov zi)
{
    name = ne, ad = add, group = gp, zali = zi;
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

istream& operator >> (istream& in, student& a){
    in >> a.name >> a.group >> a.zali >> a.ad;
    return in;
}
ostream& operator << (ostream& out, student& a){
    out << "student: ";
    out << a.name << ' ' << a.group;
    out << endl;
    out << a.zali << a.ad;
    return out;
}