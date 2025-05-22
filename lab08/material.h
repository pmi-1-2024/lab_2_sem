#include <iostream>
#pragma once
#include <string>
using namespace std;
class Material
{
protected:
	string date;
	string name;
	double volume;
	double cost;
public: 
	Material(string d = " ", string n = " ", double v = 0.0, double c = 0.0) : date(d), name(n), volume(v), cost(c) {}
	virtual ~Material() {}
	
	string getName() const { return name; }
	double getVolume() const { return volume; }
	double getCost() const { return cost; }

	friend istream& operator>>(istream& is, Material& m)
	{
		is >> m.date >> m.name >> m.volume >> m.cost;
		return is;
	}

	friend ostream& operator<<(ostream& os, const Material& m)
	{
		os << m.date << " " << m.name << " " << m.volume << " " << m.cost;
		return os;
	}
	bool sameName(const string& n) const
	{
		return name == n;
	}
	void accumulate(double v, double c)
	{
		volume += v;
		cost += c;
	}
};