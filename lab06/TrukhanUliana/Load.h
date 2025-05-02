#ifndef LOAD_H
#define LOAD_H
#include <iostream>
#include <string>
using namespace std;

struct People {
	bool baggage;
	int age;
	People() : baggage(0), age(0) {}
	People(bool b, int a) : baggage(b), age(a) {}
	People(const People& p) : baggage(p.baggage), age(p.age) {}

	string getType() const { return "People"; }
	
	void read(istream& is) {
		is >> baggage >> age;
	}
	friend istream& operator>>(istream& is, People& p) {
		p.read(is);
		return is;
	}

	void print(ostream& out) const {
		out << "People (baggage: " << baggage << ", age: " << age << ")";
	}
	friend ostream& operator<<(ostream& out, const People& p) {
		p.print(out);
		return out;
	}

	void saveRaw(ostream& out) const {
		out << baggage << " " << age;
	}
};

struct Goods {
	int weight;
	string type;
	Goods() : weight(0), type(" ") {}
	Goods(int w, string t) : weight(w), type(t) {}
	Goods(const Goods& g) : weight(g.weight), type(g.type) {}

	string getType() const { return "Goods"; }

	void print(ostream& out) const {
		out << "Goods (weight: " << weight << ", type: " << type << ")";
	}
	friend ostream& operator<<(ostream& out, const Goods& g) {
		g.print(out);
		return out;
	}

	void read(istream& is) {
		is >> weight >> type;
	}
	friend istream& operator>>(istream& is, Goods& g) {
		g.read(is);
		return is;
	}

	void saveRaw(ostream& out) const {
		out << weight << " " << type;
	}
};

#endif