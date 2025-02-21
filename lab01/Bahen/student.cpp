#include "student.h"

ostream& operator << (ostream& out, const Student& s)
{
    out << "Name:" << s.name << endl<<"Adress(" << s.adr <<")"<<endl << "Group:" << s.group <<endl<< "Zalicovca(" << s.zalicovca<<")"<<endl<<endl;
    return out;
}

istream& operator >> (istream& in, Student& s)
{
    cout << "Name: ";
    in >> s.name;
    cout << "Adress"<<endl;
    cout << "__________" << endl;
    in >> s.adr;
    cout << "Group: ";
    in >> s.group;
    cout << "Zalicovca"<<endl;
    cout << "__________"<<endl;
    in >> s.zalicovca;
    return in;
}
string Student::get_name() {
    return name;
}
string Student::get_group() {
    return group;
}
string Student::get_zip() {
    return adr.get_zip();
}
string Student::get_z_id() {
    return zalicovca.get_id();
}
bool Student::is_in_subjects(string sub) {
    return zalicovca.is_subject(sub);
}