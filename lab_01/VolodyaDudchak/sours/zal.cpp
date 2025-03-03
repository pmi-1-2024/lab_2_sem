#include <bits/stdc++.h>
#include "../head/zal.h"

zalikov::zalikov(){
    sz = 0, name = 0, preds = new predmet[0];
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