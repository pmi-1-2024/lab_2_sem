#ifndef ADRESS_H
#define ADRESS_H

#include <iostream>

using namespace std;

class Adress {
private:
	string zip;
	string city;
	string street;
public:
	string get_zip();
	friend ostream& operator << (ostream& out, const Adress& a);
	friend istream& operator >> (istream& in, Adress& a);
};


#endif