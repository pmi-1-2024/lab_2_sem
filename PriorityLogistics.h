#pragma once
#pragma once
#include "Logistics.h"
using namespace std;

template <typename T>
class PriorityLogistics : public Logistics<T> {
private:
    string priority_level;
public:
    PriorityLogistics() : Logistics<T>(), priority_level("normal") {}
    PriorityLogistics(const string& cat, const T& p, const string& t, double pr, bool discount, const string& level)
        : Logistics<T>(cat, p, t, pr, discount), priority_level(level) {}

    double CalculateDiscount() const override {
        if (this->has_discount) {
            if (priority_level == "high") return this->price * 0.2;
            if (priority_level == "medium") return this->price * 0.15;
        }
        return 0;
    }

    void Display(ostream& os) const override {
        Logistics<T>::Display(os);
        os << "\nPriority: " << priority_level;
    }

    void Input(istream& is) override {
        Logistics<T>::Input(is);
        cout << "Enter priority level: ";
        is >> priority_level;
    }
};
