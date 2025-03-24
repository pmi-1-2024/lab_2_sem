#include "phone.h"

Phone::Phone() {
	this->firm = "Nokia";
	this->name = "3310";
	this->price = 30;
}

Phone::Phone(const Phone& other) {
	this->firm = other.firm;
	this->name = other.name;
	this->price = other.price;
}

string Phone::get_name() {
	return name;
}

string Phone::get_firm() {
	return firm;
}

string Phone::get_type(){
	return "P";
}

int Phone::get_price(){
	return price;
}

void Phone::set_price(int a) {
	price = a;
}

ostream& operator << (ostream& out, Phone& ph) {
	ph.print(out);
	return out;
}

istream& operator >> (istream& in, Phone& ph) {
	ph.input(in);
	return in;
}
