#include "student.h"

Student::Student() : id(rand() % 10001), name(""), age(-1), group("") {}

std::ostream& operator<<(std::ostream& out, const Student& s) {
    out << "Id: " << s.id << " Name: " << s.name << " Age: " << s.age << " Group: " << s.group << std::endl;
    return out;
}

std::istream& operator>>(std::istream& in, Student& s) {
    std::cout << "Name: ";
    in >> s.name;
    std::cout << "Age: ";
    in >> s.age;
    std::cout << "Group: ";
    in >> s.group;
    return in;
}
