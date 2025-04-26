#ifndef SPECIALTRANSPORT_H
#define SPECIALTRANSPORT_H
#include "Transport.h"


template <typename T>
class SpecialTransport: public Transport<T> {
private:
	int discountVal;
public:
	SpecialTransport() : Transport<T>(), discountVal(0) {}
	SpecialTransport(T l, string d, double p, int dis) : Transport<T>(l, d, p), discountVal(dis) {}

	int getDiscount() const override { return discountVal; }
	void setDiscount(int d) { discountVal = d; }

	double discount(int dis) override {
		return this->getPrice() - this->getPrice() * discountVal / 100.0;
	}

	void read(istream& is) override {
		Transport<T>::read(is);
		is >> discountVal;
	}
	friend istream& operator>>(istream& is, SpecialTransport& t) {
		t.read(is);
		return is;
	}

	void print(ostream& os) const override {
		Transport<T>::print(os);
		os << ", discount: " << discountVal;
	}
	friend ostream& operator<<(ostream& os, SpecialTransport& t) {
		t.print(os);
		return os;
	}

	void saveToFile(ostream& os) const override {
		os << "s " << this->getLoadType() << " ";
		this->load.saveRaw(os);
		os << " " << this->getDestination() << " " << this->getPrice() << " " << discountVal;
	}

};

#endif