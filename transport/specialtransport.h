#ifndef SPECIALTRANSPORT_H
#define SPECIALTRANSPORT_H
#include <iostream>
#include <string>
using namespace std;
template <typename T>
class SpecialTransport : public Transport<T> {
private: 
	string specialConditions;
public:
	SpecialTransport(T c, string d, double co, string cond) :Transport<T>(c, d, co), specialConditions(cond) {}
	SpecialTransport() : Transport<T>("", "", 0.0), specialConditions(" ") {}
	void updateConditions(string cond) { specialConditions = cond; }
	double countDiscount(double percent) override {
		double ordinaryDiscount = Transport<T> ::countDiscount(percent);
		return ordinaryDiscount - (ordinaryDiscount * 0.10);
	}
	void displayInformation(ofstream& os) override {
		this->Transport<T>::displayInformation(os);
		os << "Special Conditions: " << specialConditions << endl;
	}

	friend istream& operator>> (istream& is, SpecialTransport<T>& t) {
		is >> t.cargo >> t.destination >> t.cost >> t.specialConditions;
		return is;
	}
	friend ostream& operator <<(ostream& os, const SpecialTransport<T>& t) {
		os << "Cargo:" << t.cargo << "\nDestination:" << t.destination << "\nCost:" << t.cost << "\nSpecial conditions:" << t.specialConditions;
		return os;
	}
};

#endif;