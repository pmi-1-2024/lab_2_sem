#pragma once
#include <iostream>
#include <string>
using namespace std;

struct Cable {
    string type;
    string color;
    float length; // cm

    bool operator>(const Cable& other) const;

    friend ostream& operator<<(ostream& os, const Cable& cab);
};