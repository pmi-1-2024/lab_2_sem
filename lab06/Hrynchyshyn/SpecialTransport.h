#pragma once

#include "Transport.h"
#include <iostream>
#include <string>
using namespace std;

template <typename T>
class SpecialTransport : public Transport<T> {
private:
	string specialConditions;

public:
	SpecialTransport() : specialConditions("") {}
	SpecialTransport(const SpecialTransport& other) : Transport<T>(other), specialConditions(other.specialConditions) {}
	SpecialTransport(const T& cargo, const string& destination, double cost, const string& conditions)
		: Transport<T>(), specialConditions(conditions) {
		this->cargo = cargo;
		this->destination = destination;
		this->cost = cost;
	}
	SpecialTransport& operator=(const SpecialTransport& other) {
		if (this == &other) {
			return *this;
		}
		Transport<T>::operator=(other);
		specialConditions = other.specialConditions;
		return *this;
	}
	~SpecialTransport() {}

	void setSpecialConditions(const string& conditions) { specialConditions = conditions; }

	const string& getSpecialConditions() const { return specialConditions; }

	double calculateDiscount() const override {
		if (specialConditions == "medical" || specialConditions == "special") {
			return this->cost * 0.1;
		}
		return 0.0;
	}

	void displayInfo() const override {
		Transport<T>::displayInfo();
		cout << "Special conditions: " << specialConditions << endl;
	}

	friend ostream& operator<<(ostream& os, const SpecialTransport& transport) {
		transport.displayInfo();
		return os;
	}

	friend istream& operator>>(istream& is, SpecialTransport& transport) {
		cout << "Enter cargo: ";
		is >> transport.cargo;
		cout << "Enter destination: ";
		is >> transport.destination;
		cout << "Enter transportation cost: ";
		is >> transport.cost;
		cout << "Enter special conditions: ";
		is >> transport.specialConditions;
		return is;
	}
};

