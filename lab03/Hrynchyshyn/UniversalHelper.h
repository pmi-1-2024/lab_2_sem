#pragma once

#include "VacuumCleaner.h"
#include "WashingMachine.h"
#include "Combine.h"

using namespace std;

class UniversalHelper : public VacuumCleaner, public WashingMachine, public Combine {
public:
    UniversalHelper();
    UniversalHelper(const string& b, int p, int vacPower, const string& col, int washPr, int washVol, int comPow, int comFunc);

    void print(ostream& os) const override;
    void read(istream& is) override;
};