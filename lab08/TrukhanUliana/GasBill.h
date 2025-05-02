#ifndef GASBILL_H
#define GASBILL_H
#include "Bill.h"

class GasBill : public Bill {
    size_t reg_people;

public:
    GasBill() : Bill(), reg_people(0) {}

    string getType() const override {
        return "Gas";
    }

    void read(istream& is) override {
        is >> surname >> reg_people >> paid_amount;
    }

    void print(ostream& os) const override {
        os << "Surname: " << surname << ", People count: " << reg_people
            << ", Paid: " << paid_amount;
    }
};

#endif
