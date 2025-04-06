#pragma once
#include <iostream>
#include "Transport.h"
using namespace std;
template <typename T>

class SpecialTransport :public Transport<T>
{
	string specialDelivery;
public:
	SpecialTransport(string destination, double price, T cargo, string specialDelivery) : Transport<T>(destination, price, cargo), specialDelivery(specialDelivery) {
		if (specialDelivery == "medical") {
			Transport<T>::discount(10);
		}
		else if (specialDelivery == "fragile") {
			Transport<T>::discount(5);
		}
		else if (specialDelivery == "dangerous") {
			Transport<T>::discount(15);
		}
		else {
			Transport<T>::discount(0);
		}
	}
		void print() {
			Transport<T>::print();
			cout << "Special delivery: " << specialDelivery;
			if (specialDelivery == "medical") {
				cout << " (10% discount)" << endl;
			}
			else if (specialDelivery == "fragile") {
				cout << " (5% discount)" << endl;
			}
			else if (specialDelivery == "dangerous") {
				cout << " (15% discount)" << endl;
			}
			else {
				cout << " (0% discount)" << endl;
			}
		}
		string getSpecialDelivery() {
			return specialDelivery;
		}
		void setSpecialDelivery(string specialDelivery) {
			this->specialDelivery = specialDelivery;
		}
		SpecialTransport() {}
	};