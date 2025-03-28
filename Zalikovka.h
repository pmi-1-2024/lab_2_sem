#ifndef ZALIKOVKA_H
#define ZALIKOVKA_H

#include <string>
#include "Predmet.h"
using namespace std;

class Zalikovka {
private:
    string number;
    Predmet* subjects;
    int count;
public:
    Zalikovka();
    Zalikovka(string zalnum, int subc, Predmet* subj);
    Zalikovka(const Zalikovka& zal);
    string GetNumber()const;
    Predmet* Getsubj()const;
    int Getcount()const;
    void addSub(Predmet subject);
    bool hasSub(string subname)const;
    bool hasSem(string sem)const;
    friend istream& operator>>(istream& is, Zalikovka& zal);
    friend ostream& operator<<(ostream& os, const Zalikovka& zal);
    Zalikovka& operator=(const Zalikovka& recordBook);
    ~Zalikovka();

};

#endif
