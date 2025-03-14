#include "predmet.h"

Predmet::Predmet() {
	name = "";
	term = 1;
	mark = 0;
}

ostream& operator << (ostream& out, const Predmet& p)
{
	out << "Name:" << p.name << " Term:" << p.term << " Mark:" << p.mark << endl;
	return out;
}

istream& operator >> (istream& in, Predmet& p)
{
	cout << "Name: ";
	in >> p.name;
	cout << "Term: ";
	in >> p.term;
	cout << "Mark: ";
	in >> p.mark;
	cout << "__________" << endl;
	return in;
}

string Predmet::get_name() {
	return name;
}