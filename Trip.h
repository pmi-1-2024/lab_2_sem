#ifndef TRIP_H
#define TRIP_H

#include "TripBase.h"

template<typename T>
class Trip : public TripBase {
protected:
	T cargo;
	string where;
	double cost;
public:
	Trip() { where = ""; cost = 0; }

	void input(istream& in) {
		cargo.read(in);
		in >> where >> cost;
	}

	void output(ostream& out)const {
		cargo.print(out);
		out << " -> " << where << " $" << cost << endl;
	}

	double getCost()const { return cost; }
	string getType()const { return cargo.type(); }

	void update() {
		cout << "new place: ";
		cin >> where;
		cout << "new cost: ";
		cin >> cost;
	}

	void applySale() {
		cout << "no sale for this trip\n";
	}
};

#endif
