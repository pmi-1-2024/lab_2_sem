#include "m_phone.h"

MobilePhone :: MobilePhone():Phone() {
	this->color = "Grey";
	this->storage = 32;
}
string MobilePhone::get_type(){
	return "M";
}

void MobilePhone ::print(ostream& out){
	out << get_firm() + " " + get_name() + " " + color + " " + to_string(storage) + "GB " + " price:" + to_string(price) + "usd" << endl;
}

void MobilePhone ::input(istream& in){
	in >> firm >> name >> price >> color >> storage;
}



