#pragma once

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

template <typename T>
class Transport {
protected:
	T cargo;
	string destination;
	double cost;

public:
	Transport() : cost(0.0) {}
	Transport(const Transport& other) : cargo(other.cargo), destination(other.destination), cost(other.cost) {}

	Transport& operator=(const Transport& other) {
		if (this == &other) {
			return *this;
		}
		cargo = other.cargo;
		destination = other.destination;
		cost = other.cost;
		return *this;
	}
	virtual ~Transport() {}


	void setCargo(const T& newCargo) { cargo = newCargo; }

	const T& getCargo() const {return cargo;}

	void setDestination(const string& newDestination) {destination = newDestination;}

	const string& getDestination() const {return destination;}

	void setCost(double newCost) {cost = newCost;}

	double getCost() const {return cost;}

	virtual double calculateDiscount() const {return 0.0;}

	virtual void displayInfo() const {
		cout << "Cargo: " << cargo << endl;
		cout << "Destination: " << destination << endl;
		cout << "Cost: " << fixed << cost << endl;
	}

	friend ostream& operator<<(ostream& os, const Transport& transport) {transport.displayInfo();
		return os;
	}

	friend istream& operator>>(istream& is, Transport& transport) {
		cout << "Enter cargo: ";
		is >> transport.cargo;
		cout << "Enter destination: ";
		is >> transport.destination;
		cout << "Enter transportation cost: ";
		is >> transport.cost;
		return is;
	}

protected:
	string formatDouble(double value) const {
    stringstream ss;
		ss << fixed << value;
		return ss.str();
	}
};

