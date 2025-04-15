#ifndef TRANSPORT_H
#define TRANSPORT_H
#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Transport {
private:
	T load;
	string destination;
	double price;
public:
	Transport() : load(T()), destination(" "), price(0.0) {}
	Transport(T l, string d, double p) : load(l), destination(d), price(p) {}

	T getLoad() const { return load; }
	string getDestination() const { return destination; }
	double getPrice() const { return price; }

	void setLoad(T l) { load = l; }
	void setDestination(string d) { destination = d; }
	void setPrice(double p) { price = p; }

	virtual char getTypeChar() const {
		return 't';
	}

	virtual double discount(int dis) {
		return price - price * dis / 100.0;
	}

	virtual int getDiscount() const {
		return 0;
	}

	virtual void read(istream& is) {
		is >> load >> destination >> price;
	}
	friend istream& operator>>(istream& is, Transport& t) {
		t.read(is);
		return is;
	}

	virtual void print(ostream& os) {
		os << "Load: " << load << ", destination: " << destination << ", price: " << price;
	}
	friend ostream& operator<<(ostream& os, Transport& t) {
		t.print(os);
		return os;
	}

	virtual void saveToFile(ostream& os) const {
		os << getTypeChar() << " " << load << " " << destination << " " << price;
	}
};

#endif