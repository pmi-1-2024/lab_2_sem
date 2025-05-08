#pragma once
#include "Rahunok.h"
#include <string>
#include <iostream>

using namespace std;

class WaterRah : public Rahunok {
private:
	double paidVolume;
	double lastLich;
public:
	WaterRah(): Rahunok(), paidVolume(0), lastLich(0){}

	string getType() const override {
		return "Water";
	}

	double getPaidVolume() const {
		return paidVolume;
	}

	void read(istream& is)override {
		is >> surname >> lastLich >> paidVolume >> paidAmount;
	}

	void print(ostream& os) const override {
		os << "Water rahunok | Surname: " << surname << ", Last lichilnik: " << lastLich
			<< ", Paid volume: " << paidVolume << ", Total paid: " << paidAmount;
	}

};
