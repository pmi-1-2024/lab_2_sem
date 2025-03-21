#ifndef VACUUMCLEANER_H
#define VACUUMCLEANER_H

#include "Electroprilad.h"

class VacuumCleaner : public Electroprilad {
private:
    int power;  
    string color;  

public:
    VacuumCleaner();
    VacuumCleaner(string n, string f, int p, int pw, string c);
    VacuumCleaner(const VacuumCleaner& vc);
    ~VacuumCleaner() {}

    void print(ostream& os) const override;
    void write(istream& is) override;
};

#endif

