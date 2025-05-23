#include "CommaDashCheck.h"

CommaDashCheck::CommaDashCheck(const vector<char>& d) : data(d) {}

bool CommaDashCheck::operator()(int i) const {
    return data[i] == ',' && i + 1 < data.size() && data[i + 1] == '-';
}