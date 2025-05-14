#include "Brigade.h"
#include <algorithm>

using namespace std;

Brigade::Brigade() : brigadeNumber(0), foreman(" ") {}
Brigade::Brigade(int num, const string& f) : brigadeNumber(num), foreman(f) {}

int Brigade::getNumber() const { return brigadeNumber; }
string Brigade::getForeman() const { return foreman; }

void Brigade::addMaterial(const Material& m) {
	materials.push_back(m);
}

const vector<Material>& Brigade::getMaterials() const {
	return materials;
}

void Brigade::printMaterials(ostream& out) const {
	out << "Brigade #" << brigadeNumber << "  foreman: " << foreman << "\n";
	for (const auto& m : materials) {
		m.print(out);
	}
	out << endl;
}

void Brigade::printSortedByDate(ostream& out) const {
	vector<Material> sorted = materials;
	sort(sorted.begin(), sorted.end());
	double total = 0;
	out << "Expenses for brigade #" << brigadeNumber << " by date:\n";
	for (const auto& m : sorted) {
		m.print(out);
		total += m.getCost();
	}
	out << "Total expenses: " << total << " UAH\n";
}

bool compareByForeman(const Brigade& a, const Brigade& b) {
	return a.getForeman() < b.getForeman();
}
