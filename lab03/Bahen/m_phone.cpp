#include "m_phone.h"

MobilePhone :: MobilePhone():Phone() {
	this->color = "";
	this->storage = 32;
}
string MobilePhone::get_type(){
	return "M";
}

void MobilePhone ::print(ostream& out){
	out << firm + " " + name + " " + color + " " + to_string(storage) + "GB " + " price:" + to_string(price) + "usd" << endl;
}

void MobilePhone ::input(istream& in){
	in >> firm >> name >> price >> color >> storage;
}

ostream& operator << (ostream& out, MobilePhone& ph) {
	ph.print(out);
	return out;
}

istream& operator >> (istream& in, MobilePhone& ph) {
	ph.input(in);
	return in;
}


