#include <bits/stdc++.h>
#include "../head/zal.h"

zalikov::zalikov(){
    sz = 0, name = 0, preds = 0;
}
zalikov::zalikov(int zp, int ct, predmet* pd)
{
    sz = zp, name = ct, preds = pd;
}
predmet zalikov::getPred(int i){
    return preds[i];
}


int zalikov::getZali(){
    return name;
}
int zalikov::getZaliSz()
{
    return sz;
}

istream& operator >> (istream& in, zalikov& a){
    in >> a.name>> a.sz;
    a.preds = new predmet[a.sz];
    for(int i = 0; i < a.sz;i++)
        in >> a.preds[i];
    return in;
}
ostream& operator << (ostream& out, zalikov& a){
    out << "Zalick: ";
    out << a.name << ' ' << a.sz << ' ' << endl;
    for(int i = 0; i < a.sz;i++)
        out << a.preds[i];
    return out;
}

zalikov& zalikov::operator=(zalikov& a){
    if (this == &a) { 
        return *this;
    }
    name = a.name;
    sz = a.sz;
    preds = new predmet[sz];
    for (int i = 0; i < sz; i++) preds[i] =a.preds[i];
    return *this;
}

predmet& zalikov::operator[](int a){
    if(a >= sz)
    {
        cout << "out of range";
        exit(0);
    }
    return preds[a];
}

zalikov::zalikov(zalikov& a){
    name = a.name;
    sz = a.sz;
    preds = new predmet[sz];
    for (int i = 0; i < sz; i++) preds[i] =a.preds[i];
}
