#include "Zalikovka.h"
#include <iostream>
using namespace std;

Zalikovka::Zalikovka(){}

Zalikovka::Zalikovka(string zalnum): number(zalnum), count(0){}

string Zalikovka:: GetNumber()const {
    return number;
}
bool Zalikovka::hasSem(string sem)const {
    for (int i = 0; i < count; i++) {
        if (subjects[i].GetSem() == sem) {
            return true;
            return false;
        }
    }
}
bool Zalikovka::hasSub(string sub)const {
    for (int i = 0; i < count; i++) {
        if (subjects[i].GetName() == sub) {
            return true;
            return false;
        }   
}
}
void Zalikovka::addSub(Predmet subject) {
    if (count < 5) subjects[count++] = subject;
}

istream& operator>>(istream& is, Zalikovka& zal)
{
    cout << "\nEnter number of zalikovka: ";
    is >> zal.number;
    cout << "\nEnter count of subjects (not more than 5): ";
    is >> zal.count;
    if (zal.count > 5) zal.count = 5;
    for (int i = 0; i < zal.count; i++) {
        cout << "Entering " << i + 1 << " student data:" << endl;
        cin>>zal.subjects[i];
    }
    return is;
}
ostream& operator<<(ostream& os, const Zalikovka& zal) {
    os << "\nNumber: " << zal.number;
    os << "\nCount of subject: " << zal.count;
    os << "\nSubjects: ";
    for (int i = 0; i < zal.count; i++) {
        cout << zal.subjects[i];
    }
    return os;
}
