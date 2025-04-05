#include "RadioPhone.h"

RadioPhone::RadioPhone() { range = 0; answer = 0; }


void RadioPhone::read(istream& in) {

	in >> name >> brand >> price >> range >> answer;
}

void RadioPhone::write(ostream& out)const {


	out << "RadioPhone: " << name << " " << brand << " " << price << " " << range << " ";
	if (answer) out << "Yes" << endl;
	else out << "No" << endl;
}
