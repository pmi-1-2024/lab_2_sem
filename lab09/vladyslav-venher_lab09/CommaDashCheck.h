#pragma once
#include <vector>
using namespace std;

struct CommaDashCheck {
    const vector<char>& data;
    CommaDashCheck(const vector<char>& d);
    bool operator()(int i) const;
};