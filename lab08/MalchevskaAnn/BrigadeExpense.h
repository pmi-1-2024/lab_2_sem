#pragma once
#include <string>

using namespace std;

struct Material {
    string date;
    string name;
    double volume;
    double cost;
    friend ostream& operator<<(ostream& os, const Material& mat);
    friend istream& operator>>(istream& is, Material& mat);
    friend bool operator==(const Material& a, const Material& b);
};

struct Foreman {
    string name;
    int age;
    friend ostream& operator<<(ostream& os, const Foreman& foreman);
    friend istream& operator>>(istream& is, Foreman& foreman);
    friend bool operator==(const Foreman& a, const Foreman& b);
};

class BrigadeExpense {
private:
    int brigadeNumber;
    Foreman foreman;
    vector<Material> materials;

public:
    BrigadeExpense() = default;
    void setBrigadeNumber(int number) { brigadeNumber = number; }
    int getBrigadeNumber() const { return brigadeNumber; }
    void setForeman(const Foreman& f) { foreman = f; }
    Foreman getForeman() const { return foreman; }
    void addMaterial(const Material& m) { materials.push_back(m); }
    vector<Material> getMaterials() const { return materials; }
    friend ostream& operator<<(ostream& os, const BrigadeExpense& exp);
    friend istream& operator>>(istream& is, BrigadeExpense& exp);
    friend bool operator==(const BrigadeExpense& a, const BrigadeExpense& b);
};
