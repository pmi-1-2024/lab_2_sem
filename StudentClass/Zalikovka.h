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
    void input();
    void display();
    string GetNumber()const;
    void addSub(Predmet subject);
    bool hasSub(string subname)const;
    bool hasSem(string sem)const;


};

#endif
