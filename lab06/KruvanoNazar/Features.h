#ifndef FEATURES_H
#define FEATURES_H
#include <iostream>
#include <string>
#include <fstream>
#include "TransportsABS.h"
#include "Passenger.h"
#include "Cargo.h"
using namespace std;

template <typename T>
class Transport : public TransportsABS {
protected:
	string type;
	T vantag;
	string destination;
	double cost;
	bool trdiscount;
public:
	Transport() : type("no"),vantag(T()), destination("nodest"), cost(0.0), trdiscount(false) {}
	Transport(string t,T v, string des, double c, bool td) : type(t),vantag(v), destination(des), cost(c), trdiscount(td) {}
	string GetType() override {
		return type;
	}
	void SetVantag() override {
		T temp;
		cin >> temp;
		vantag = temp;
	}
	bool GetDiscount() override {
		return trdiscount;
	}
	string GetDest() override {
		return destination;
	}
	double GetCost() override {
		return cost;
	}
	void SetDest(string dest) {
		destination = dest;
	}
	void SetCost(double c) {
		cost = c;
	}
	virtual double Discount() override {
		if (destination == "Ukrane" && trdiscount == true) {
			return GetCost() * 0.4;
		}else if (destination == "Ukrane" || trdiscount == true) {
			return GetCost() * 0.2;
		}
		return 0.0;
	}
	virtual double FinalCost() override {
		return this->cost - Discount();
	}
	virtual void print(ostream& os)const override {
		os << "\nVantag: " << vantag;
		os << "\nDestination: " << destination;
		os << "\nCost: " << cost;
	}
	virtual void read(istream& input) override {
		input >>type >> vantag >> destination >> cost >> trdiscount;
	}
	friend istream& operator >>(istream& input, Transport& tr) {
		tr.read(input);
		return input;
	}
	friend ostream& operator <<(ostream& os, const Transport& tr) {
		tr.print(os);
		return os;
	}
};
template<typename T>
class SpecialTransport : virtual public Transport<T> {
private:
	string clas;
public:
	SpecialTransport() : Transport<T>(), clas("noclas") {}
	SpecialTransport(T vt, string ds, double cs, string cl) : Transport<T>(vt, ds, cs), clas(cl) {}

	double FinalCost()override {
		return (this->GetCost() - Transport<T>::Discount()) - SpecialTransport::Discount();
	}
	void print(ostream&os) const override {
		Transport<T>::print(os);
		os << "\nClas:" << clas;
	}
	void read(istream& input) override {
		Transport<T>::read(input);
		input >> clas;
	}
	friend istream& operator >>(istream& input, SpecialTransport& st) {
		st.read(input);
		return input;
	}
	friend ostream& operator<<(ostream& os, const SpecialTransport& st) {
		st.print(os);
		return os;
	}
	double Discount() override {
		if (clas == "VIP") {
			return this->GetCost() * 0.4;
		}
		if (clas == "Premium") {
			return this->GetCost() * 0.5;
		}
		return 0.0;
	}
};
void ReadFromFile(ifstream& file, TransportsABS** transports, int& count);
int TheMostExpTr(TransportsABS** transports, int& count);
void SetDiscount(TransportsABS** transports, int& count);
double FInalTRScost(TransportsABS** transports, int& count);
void startmenu();		
void transportmenu(TransportsABS** transports, int& count, int choice, int& d);
#endif

