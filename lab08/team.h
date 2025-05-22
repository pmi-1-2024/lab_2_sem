#include "material.h"
#pragma once
#include <iostream>
#include <list>
using namespace std;

class Team {
protected:
	int number;
	string master;
	list <Material> materials;
public:
	Team(int n = 0, string m = " ") : number(n), master(m) {}
	int getNumber() const { return number; }
	string getMaster() const { return master; }
	list<Material> getMaterials() const { return materials; }

	void addMaterial(const Material& m) {
		materials.insert(materials.end(), m); 
	}

friend istream& operator>>(istream& is, Team& t) {
	is >> t.number >> t.master;
	return is;
}

friend ostream& operator<<(ostream& os, const Team& t) {
	os <<"Team " << t.number << " Master " << t.master << endl;
	for (const auto& m : t.materials) {
		os << "\t"<< m << endl;
	}
	return os;
}
};