#include "Zalikovka.h"
#include <iostream>
using namespace std;

Zalikovka::Zalikovka() : number(0), count(0) {}

Zalikovka::Zalikovka(string zalnum): number(zalnum), count(0){}

void Zalikovka::input() {
    cout << "Введіть номер заліковки: ";
    cin >> number;
    cout << "Введіть кількість предметів (не більше 5): ";
    cin >> count;
    if (count > 5) count = 5;
    for (int i = 0; i < count; i++) {
        cout << "Введення даних для предмета " << i + 1 << ":" << endl;
        subjects[i].input();
    }
}

void Zalikovka::display() {
    cout << "Заліковка №" << number << endl;
    for (int i = 0; i < count; i++) {
        subjects[i].display();
    }
}
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
