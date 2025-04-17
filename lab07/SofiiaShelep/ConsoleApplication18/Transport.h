#pragma once
#include <iostream>
using namespace std;
template <typename T>
class Transport
{
private:
	string destination;
	double price;
	T cargo;
public:
	Transport(string destination, double price, T cargo) : destination(destination), price(price), cargo(cargo) {}
	virtual void print() {
		cout << "Destination: " << destination << endl;
		cout << "Price: " << price << endl;
		cout << "Cargo: " << cargo << endl;
	}
	string getDestination() {
		return destination;
	}
	double getPrice() {
		return price;
	}
	T getCargo() {
		return cargo;
	}
	void setDestination(string destination) {
		this->destination = destination;
	}
	void setPrice(double price) {
		this->price = price;
	}
	void setCargo(T cargo) {
		this->cargo = cargo;
	}
	void discount(double percent) {
		price = price - price * percent / 100;
	}
	Transport() {}

};

