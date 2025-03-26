#include "Student.h"

Student::Student() : name("noname"), group("nogroup"), avarage_mark(0.0) {}

Student::Student(string n, string g, double avm) :name(n), group(g), avarage_mark(avm) {}

Student::Student(const Student& stud) : name(stud.name), group(stud.group), avarage_mark(stud.avarage_mark) {}

Student& Student::operator=(const Student& st)
{
	if (this == &st) {
		return *this;
	}
	name = st.name;
	group = st.group;
	avarage_mark = st.avarage_mark;
	return *this;
}

bool Student::operator==(const Student& other) const
{
	return (name==other.name)&&(group== other.group)&&(avarage_mark== other.avarage_mark);
}

string Student::GetName()const
{
	return name;
}

string Student::GetGroup()const
{
	return group;
}

double Student::GetAvM()const
{
	return avarage_mark;
}

istream& operator>>(istream& is, Student& stud)
{
	cout << "\nEnter student`s name: ";
	is >> stud.name;
	cout << "\nEnter student`s group: ";
	is >> stud.group;
	cout << "\nEnter student`s avarage mark: ";
	is >> stud.avarage_mark;
	return is;
}

ostream& operator<<(ostream& os, const Student& stud)
{
	os << "\nName: " << stud.name;
	os << "\nGroup: " << stud.group;
	os << "\nAvarage mark: " << stud.avarage_mark;
	return os;
}

