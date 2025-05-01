#ifndef FEATURES_H
#define FEATURES_H
#include <iostream>
#include <string>	
#include <fstream>
using namespace std;

class InvalidTransportDataException : public exception {
	string message;
public:
	InvalidTransportDataException(const string& msg) : message(msg) {}
	const char* what() const noexcept override {
		return message.c_str();
	}
};

template <typename T>
class Transport {
protected:
	T vantag;
	string destination;
	double cost;
public:
	Transport() : vantag(T()), destination("nodest"), cost(0.0) {}
	Transport(T v, string des, double c) : vantag(v), destination(des), cost(c) {}
	T Getvantag() {
		return vantag;
	}
	string GetDest() {
		return destination;
	}
	double GetCost() {
		return cost;
	}
	void SetVantag(T vant) {
		vantag = vant;
	}
	void SetDest(string dest) {
		destination = dest;
	}
	void SetCost(double c) {
		cost = c;
	}
	virtual double Discount() {
		if (vantag == "Medicine") {
			return GetCost() * 0.3;
		}
		if (vantag == "Passenger") {
			return GetCost() * 0.2;
		}
		return 0.0;
	}
	virtual double FinalCost() {
		return this->cost - Discount();
	}
	virtual void print(ostream& os)const {
		os << "\nVantag: " << vantag;
		os << "\nDestination: " << destination;
		os << "\nCost: " << cost;
	}
	virtual void read(istream& input){
		input >> vantag >> destination >> cost;
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
class SpecialTransport : public Transport<T> {
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
void ReadFromFile(ifstream& file, Transport<string>** transports, int& count);
int TheMostExpTr(Transport<string>** tranports, int& count);
void SetDiscount(Transport<string>** transports, int& count);
double FInalTRScost(Transport<string>** transpoerts, int& count);
void startmenu();		
void transportmenu(Transport<string>** transports, int& count, int choice, int& d);
#endif

