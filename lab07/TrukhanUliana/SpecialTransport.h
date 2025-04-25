#ifndef SPECIALTRANSPORT_H
#define SPECIALTRANSPORT_H
#include "Transport.h"

template <typename T>
class SpecialTransport: public Transport<T> {
private:
	string type;
	int discountVal;
public:
	SpecialTransport() : Transport<T>(), type(" "), discountVal(0) {}
	SpecialTransport(T l, string d, double p, string t, int dis) : Transport<T>(l, d, p), type(t), discountVal(dis) {}

	string getType() { return type; }
	int getDiscount() const override { return discountVal; }
	void setType(string t) { type = t; }
	void setDiscount(int d) { discountVal = d; }

	char getTypeChar() const override {
		return 's';
	}

	double discount(int dis) override {
		return this->getPrice() - this->getPrice() * discountVal / 100.0;
	}

	void read(istream& is) override {
		Transport<T>::read(is);
		is >> type >> discountVal;
		if (!is) {
			throw runtime_error("Error: failed to read Special Transport data from stream.");
		}
	}
	friend istream& operator>>(istream& is, SpecialTransport& t) {
		t.read(is);
		return is;
	}

	void print(ostream& os) override {
		Transport<T>::print(os);
		os << ", type: " << type << ", discount: " << discountVal;
	}
	friend ostream& operator<<(ostream& os, SpecialTransport& t) {
		t.print(os);
		return os;
	}

	void saveToFile(ostream& os) const override {
		os << getTypeChar() << " " << this->getLoad() << " " << this->getDestination()
			<< " " << this->getPrice() << " " << type << " " << discountVal;
	}
};

#endif