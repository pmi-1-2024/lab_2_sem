#include "Material.h"

using namespace std;

Material::Material() : date("unknown"), name("unknown"), volume(0.0), cost(0.0) {}
Material::Material(const string& d, const string& n, double v, double c)
    : date(d), name(n), volume(v), cost(c) {}

string Material::getDate() const { return date; }
string Material::getName() const { return name; }
double Material::getVolume() const { return volume; }
double Material::getCost() const { return cost; }

void Material::print(ostream& out) const {
    out << date << " " << name << " " << volume << " " << cost << endl;
}

bool Material::operator<(const Material& other) const {
    return date < other.date; 
}

istream& operator>>(istream& in, Material& m) {
    return in >> m.date >> m.name >> m.volume >> m.cost;

}
ostream& operator<<(ostream& out, const Material& m) {
    m.print(out);
    return out;
}
