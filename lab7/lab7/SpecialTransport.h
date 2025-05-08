#pragma once
#include "Transport.h"

template <typename T>
class SpecialTransport : public Transport<T> {
private:
    string specialCondition;

public:
    SpecialTransport(T tpCrg = T(), double cstDel = 0, string dstn = "", double maxL = 0, string condition = "")
        : Transport<T>(tpCrg, cstDel, dstn, maxL), specialCondition(condition) {}

    void printInfo() const override {
        Transport<T>::printInfo();
        cout << " Special Condition: " << specialCondition << endl;
    }

    void updateSpecialCondition(const string& condition) {
        specialCondition = condition;
    }

    void expediteDelivery() {
        if (specialCondition == "Expedited") {
            this->costOfDeliv *= 1.20;
            cout << "Delivery expedited! New cost: $" << this->costOfDeliv << endl;
        }
        else {
            cout << "No expedited delivery condition set." << endl;
        }
    }
};
