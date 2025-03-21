#include "c_phone.h"

ComboPhone::ComboPhone():Phone(),MobilePhone(),RadioPhone(){}

string ComboPhone::get_type(){
	return "C";
}

void ComboPhone::input(istream & in){
	in >> firm >> name >> price >> color >> storage >> radius >> is_auto;
}

void ComboPhone::print(ostream & out){
	out << firm + " " + name + " " + color + " " + to_string(storage) + "GB " + to_string(radius) + "km " + "answering machine:" + to_string(is_auto) + " price:" + to_string(price) + "usd" << endl;
}

ostream& operator << (ostream& out, ComboPhone& ph) {
	ph.print(out);
	return out;
}

istream& operator >> (istream& in, ComboPhone& ph) {
	ph.input(in);
	return in;
}
