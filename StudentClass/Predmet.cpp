#include "Predmet.h"
#include <iostream>
using namespace std;

Predmet::Predmet() : name(""), semester(0), grade(0) {}
Predmet::Predmet(string n,string s,int g): name(n), semester(s), grade(g){}


void Predmet::input() {
    cout << "������ ����� ��������: ";
    cin >> name;
    cout << "������ ����� ��������: ";
    cin >> semester;
    cout << "������ ������: ";
    cin >> grade;
}

void Predmet::display() {
    cout << "�������: " << name << ", �������: " << semester << ", ������: " << grade << endl;
}
string Predmet::GetName() const {
    return name;
}
string Predmet::GetSem() const {
    return semester;
}
int Predmet::GetGrade()const {
    return grade;
}
