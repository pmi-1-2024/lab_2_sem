#ifndef WATERBILL_H
#define WATERBILL_H

#include "Bill.h"

class WaterBill : public Bill {
    double last_counter;
    double paid_volume;

public:
    WaterBill() : Bill(), last_counter(0), paid_volume(0) {}

    string getType() const override {
        return "Water";
    }

    void read(istream& is) override {
        is >> surname >> last_counter >> paid_volume >> paid_amount;
    }

    void print(ostream& os) const override {
        os << "Surname: " << surname << ", Last counter: " << last_counter
            << ", Paid volume: " << paid_volume << ", Paid: " << paid_amount;
    }
};

#endif
