#ifndef TRANSPORT_H
#define TRANSPORT_H
#include <iostream>
#include <string>
#include "Load.h"
#include "AllTransport.h"
using namespace std;

template <typename T>
class Transport : public AllTransport {
private:
	string destination;
	double price;
protected:
	T load;
public:
	Transport() : load(T()), destination(" "), price(0.0) {}
	Transport(T l, string d, double p) : load(l), destination(d), price(p) {}

	string getLoad() const override { return load.getType(); }
	string getDestination() const override { return destination; }
	double getPrice() const override { return price; }
	string getLoadType() const override { return load.getType(); }
	int getDiscount() const override { return 0; }

	void setLoad(T l) { load = l; }
	void setDestination(string d) { destination = d; }
	void setPrice(double p) override { price = p; }

	double discount(int dis) override {
		return price - price * dis / 100.0;
	}

	void read(istream& is) override{
		is >> load >> destination >> price;
	}
	friend istream& operator>>(istream& is, Transport& t) {
		t.read(is);
		return is;
	}

	void print(ostream& os) const override {
		os << "Load: " << load << ", destination: " << destination << ", price: " << price;
	}
	friend ostream& operator<<(ostream& os, Transport& t) {
		t.print(os);
		return os;
	}

	void saveToFile(ostream& os) const override {
		os << "t " << load.getType() << " ";
		load.saveRaw(os);
		os << " " << destination << " " << price;
	}
};

#endif