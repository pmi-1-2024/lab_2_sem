#ifndef HYBRIDROBOTDONKEY_H
#define HYBRIDROBOTDONKEY_H

#include "Mule.h"

class HybridRobotDonkey : public Mule {
    string robotFunctionality;

public:
    HybridRobotDonkey(const string& name = "", int birthYear = 0,
        const string& color = "", const string& breed = "",
        const string& type = "", double height = 0,
        const string& nickname = "",
        const string& robotFunctionality = "")
        : Mule(name, birthYear, color, breed, type, height, nickname),
        robotFunctionality(robotFunctionality) {
    }

    void display(ostream& os) const override {
        Mule::display(os);
        os << "Robot Functionality: " << robotFunctionality << '\n';
    }

    bool matchesCriteria(const string& parameter) const override {
        return robotFunctionality == parameter ||
            Mule::matchesCriteria(parameter);
    }

    void performRobotTask() const {
        cout << "Performing robot functionality: " << robotFunctionality << "!\n";
    }
};

#endif
