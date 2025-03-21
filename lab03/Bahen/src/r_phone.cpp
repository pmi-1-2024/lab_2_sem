#include "r_phone.h"

RadioPhone::RadioPhone() :Phone() {
	this->radius = 100;
	this->is_auto = false;
}
bool RadioPhone::has_auto(){
	return is_auto;
}
string RadioPhone::get_type(){
	return "R";
}

void RadioPhone::print(ostream& out) {
	out << firm + " " + name + " " + to_string(radius) + "km " + "answering machine:" + to_string(is_auto) + " price:" + to_string(price) + "usd"<<endl;
}

void RadioPhone ::input(istream& in){
	in >> firm >> name >> price >> radius >> is_auto;
}

ostream& operator << (ostream& out, RadioPhone& ph) {
	ph.print(out);
	return out;
}

istream& operator >> (istream& in, RadioPhone& ph) {
	ph.input(in);
	return in;
}
