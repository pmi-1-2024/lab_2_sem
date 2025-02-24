#ifndef ZALIKOVKA_H
#define ZALIKOVKA_H

#include <string>
#include "Predmet.h"
using namespace std;

class Zalikovka {
private:
    string number;
    Predmet subjects[5];
    int count;
public:
    Zalikovka();
    Zalikovka(string zalnum);
    string GetNumber()const;
    void addSub(Predmet subject);
    bool hasSub(string subname)const;
    bool hasSem(string sem)const;
    friend istream& operator>>(istream& is, Zalikovka& zal);
    friend ostream& operator<<(ostream& os, const Zalikovka& zal);

};

#endif
