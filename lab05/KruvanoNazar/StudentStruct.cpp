#include "StudentStruct.h"

Student::Student() : name("noname"), surname("nosurname"), mark(0) {}

bool Student::operator>(const Student& stud)
{
	if (mark != stud.mark)
		return mark > stud.mark;

	if (surname != stud.surname)
		return surname > stud.surname;

	return name > stud.name;
}

istream& operator>>(istream& is, Student& stud)
{
	cout << "\nEnter student`s name: ";
	is >> stud.name;
	cout << "\nEnter student`s surname: ";
	is >> stud.surname;
	cout << "\nEnter student`s mark: ";
	is >> stud.mark;
	return is;
}

ostream& operator<<(ostream& os, const Student& stud)
{
	os << "\nName: " << stud.name;
	os << "\nSurname: " << stud.surname;
	os << "\nMark: " << stud.mark;
	return os;
}
