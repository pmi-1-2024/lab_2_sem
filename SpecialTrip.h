#ifndef SPECIALTRIP_H
#define SPECIALTRIP_H

#include "Trip.h"

template<typename T>
class SpecialTrip : public Trip<T> {
	int sale;
public:
	SpecialTrip() { sale = 0; }

	void input(istream& in) {
		this->cargo.read(in);
		in >> this->where >> this->cost >> sale;
	}

	void output(ostream& out)const {
		this->cargo.print(out);
		out << " -> " << this->where << " $" << this->cost << " (sale " << sale << "%)\n";
	}

	void applySale() {
		this->cost -= this->cost * sale / 100.0;
		cout << "new cost with sale: " << this->cost << endl;
	}
};

#endif
