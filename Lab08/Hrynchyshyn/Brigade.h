#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Material.h"
using namespace std;

class Brigade {
private:
    int brigadeNumber;
    string foreman;
    vector<Material> materials;

public:
    Brigade();
    Brigade(int, const string&);
    int getNumber() const;
    string getForeman() const;

    void addMaterial(const Material&);
    const vector<Material>& getMaterials() const;

    void printMaterials(ostream&) const;
    void printSortedByDate(ostream&) const;
};

bool compareByForeman(const Brigade&, const Brigade&);
