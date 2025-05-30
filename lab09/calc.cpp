#include "calc.h"
#include <string>
#include <algorithm>

bool IsChildAt::operator()(vector<char>::iterator it) {
    string target = "child";
    if (end - it < target.size()) return false;
    return equal(target.begin(), target.end(), it);
}