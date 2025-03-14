#include "Zalikovka.h"
#include <iostream>
using namespace std;

Zalikovka::Zalikovka(): number("nonumber"),subjects(nullptr),count(0){}

Zalikovka::Zalikovka(string zalnum, int subc, Predmet* subj): number(zalnum), count(0), subjects(subj){}

Zalikovka::Zalikovka(const Zalikovka& zal)
{
    number = zal.number;
    count = zal.count;
    subjects = new Predmet[count];
    for (int i = 0; i < count; i++) {
        subjects[i] = zal.subjects[i];
    }
}

string Zalikovka:: GetNumber()const {
    return number;
}
Predmet* Zalikovka::Getsubj() const {
    return subjects;
}

int Zalikovka::Getcount() const
{
    return count;
}

bool Zalikovka::hasSem(string sem)const {
    for (int i = 0; i < count; i++) {
        if (subjects[i].GetSem() == sem) {
            return true;
        }
        return false;
    }
}

bool Zalikovka::hasSub(string sub)const {
    for (int i = 0; i < count; i++) {
        if (subjects[i].GetName() == sub) {
            return true;
        }   
        return false;
}
}
void Zalikovka::addSub(Predmet subject) {
    Predmet* newSub = new Predmet[count + 1];
    for (int i = 0; i < count; i++) {
        if(subjects!=nullptr)
        newSub[i] = subjects[i];
    }
    newSub[count] = subject;
    delete[] subjects;
    subjects = newSub;
    count++;
}
istream& operator>>(istream& is, Zalikovka& zal)
{
    is >> zal.number;
    string subname;
    string sem;
    int grade;
    while (is >> subname) {
        if (subname == "END") break;
        is >> sem >> grade;
        zal.addSub(Predmet(subname, sem, grade));
    }
    return is;
}
ostream& operator<<(ostream& os, const Zalikovka& zal) {
    os << "\nNumber: " << zal.number;
    os << "\nCount of subject: " << zal.count;
    os << "\nSubjects: ";
    for (int i = 0; i < zal.count; i++) {
        os << zal.subjects[i];
    }
    return os;
}
Zalikovka& Zalikovka::operator=(const Zalikovka& zal)
{
    if (this == &zal) {
        return *this;
    }
    number = zal.number;
    count = zal.count;
    delete[]subjects;
    subjects = new Predmet[count];
    for (int i = 0; i < count; i++) {
        subjects[i] = zal.subjects[i];
    }
    return *this;
}

Zalikovka::~Zalikovka()
{
    delete[]subjects;
}
