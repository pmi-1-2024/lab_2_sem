#ifndef FEATURES_H
#define FEATURES_H
#include <iostream>
#include <deque>
#include <fstream>
#include <string>
#include "WaterBill.h"
#include "GasBill.h"
using namespace std;

class InvalidBillDataException : public exception {
	string message;
public:
	InvalidBillDataException(const string& msg) : message(msg) {}
	const char* what() const noexcept override {
		return message.c_str();
	}
};

void ReadFile(ifstream& file, deque<Bill*>& bills, deque<Bill*>& Gbills);
bool CompareBills(const Bill* a, const Bill* b);
#endif