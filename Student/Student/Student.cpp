#include "Student.h"
#include <iostream>
using namespace std;

Student::Student(string name, Adress adress, string group, Zalik zalik) :
    name(name), adress(adress), group(group), zalik(zalik) {
}

void Student::print() {
    cout << name << ":" << "\n\tÃðóïà: " << group << "." << endl;
    zalik.print();
    adress.print();
}

string Student::getName() { return name; }
string Student::getGroup() { return group; }
Adress Student::getAdress() { return adress; }
Zalik Student::getZalik() { return zalik; }

