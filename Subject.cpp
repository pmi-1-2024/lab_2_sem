#include "Subject.h"

ostream& operator<<(ostream& out, const Subject& sub) {
    out << "Предмет: " << sub.name << " | Семестр: " << sub.semester << " | Оцінка: " << sub.grade;
    return out;
}

istream& operator>>(istream& in, Subject& sub) {
    cout << "Введіть назву предмета: ";
    in >> sub.name;
    cout << "Введіть семестр: ";
    in >> sub.semester;
    cout << "Введіть оцінку: ";
    in >> sub.grade;
    return in;
}
