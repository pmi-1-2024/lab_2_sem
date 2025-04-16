#include "student.h"

Student::Student(){
    	id = rand() % 10001;;
    	name = "";
    	age = -1;
    	group = 1;
    }

ostream& operator << (ostream& out, const Student& s)
{
    out <<"Id:" << s.id << " Name:" << s.name << " Age:" << s.age << " Group:" << s.group << endl;
    return out;
}

istream& operator >> (istream& in, Student& s)
{
    cout << "Name: ";
    in >> s.name;
    cout << "Age: ";
    in >> s.age;
    cout << "Group: ";
    in >> s.group;
    cout <<endl;
    return in;
}
