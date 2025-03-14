#include "Zalikovka.h"
#include <iostream>
#include <cstring>


Zalikovka::Zalikovka() {
    number = "";
    subjects = nullptr;
    count = 0;
}


Zalikovka::Zalikovka(string zalnum, int subc, Predmet* subj) {
    number = zalnum;
    count = subc;
    subjects = new Predmet[count];
    for (int i = 0; i < count; i++) {
        subjects[i] = subj[i];
    }
}


Zalikovka::Zalikovka(const Zalikovka& zal) {
    number = zal.number;
    count = zal.count;
    subjects = new Predmet[count];
    for (int i = 0; i < count; i++) {
        subjects[i] = zal.subjects[i];
    }
}


string Zalikovka::GetNumber() const {
    return number;
}


Predmet* Zalikovka::Getsubj() const {
    return subjects;
}


int Zalikovka::Getcount() const {
    return count;
}


void Zalikovka::addSub(Predmet subject) {
    Predmet* temp = new Predmet[count + 1];
    for (int i = 0; i < count; i++) {
        temp[i] = subjects[i];
    }
    temp[count] = subject;
    delete[] subjects;
    subjects = temp;
    count++;
}


bool Zalikovka::hasSub(string subname) const {
    for (int i = 0; i < count; i++) {
        if (subjects[i].GetName() == subname) {
            return true;
        }
    }
    return false;
}


istream& operator>>(istream& is, Zalikovka& zal) {
    cout << "Enter number of zalikivka: ";
    is >> zal.number;

    cout << "Enter the number of subjects: ";
    is >> zal.count;

    zal.subjects = new Predmet[zal.count];
    for (int i = 0; i < zal.count; i++) {
        is >> zal.subjects[i];
    }

    return is;
}


ostream& operator<<(ostream& os, const Zalikovka& zal) {
    os << "Zalikovka Number: " << zal.number << endl;
    os << "Subjects: " << endl;
    for (int i = 0; i < zal.count; i++) {
        os << zal.subjects[i] << endl;
    }
    return os;
}


Zalikovka& Zalikovka::operator=(const Zalikovka& recordBook) {
    if (this == &recordBook) {
        return *this;
    }

    number = recordBook.number;
    count = recordBook.count;

    delete[] subjects;
    subjects = new Predmet[count];
    for (int i = 0; i < count; i++) {
        subjects[i] = recordBook.subjects[i];
    }

    return *this;
}


Zalikovka::~Zalikovka() {
    delete[] subjects;
}
