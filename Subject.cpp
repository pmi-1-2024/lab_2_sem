#include "Subject.h"

ostream& operator<<(ostream& out, const Subject& sub) {
    out << "�������: " << sub.name << " | �������: " << sub.semester << " | ������: " << sub.grade;
    return out;
}

istream& operator>>(istream& in, Subject& sub) {
    cout << "������ ����� ��������: ";
    in >> sub.name;
    cout << "������ �������: ";
    in >> sub.semester;
    cout << "������ ������: ";
    in >> sub.grade;
    return in;
}
