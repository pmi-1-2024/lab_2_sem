#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <iostream>
using namespace std;

struct Student {
	string name;
	int age;
	double rating;

	void read() {
		cin >> name >> age >> rating;
	}

	void print() const {
		cout << name << " " << age << " " << rating << endl;
	}
};

#endif
