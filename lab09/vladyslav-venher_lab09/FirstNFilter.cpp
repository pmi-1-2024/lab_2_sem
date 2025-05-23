#include "FirstNFilter.h"

FirstNFilter::FirstNFilter(int n) : limit(n) {}

bool FirstNFilter::operator()(char ch) {
    if (isValid(ch)) {
        if (count < limit) {
            count++;
            return true;
        }
    }
    return false;
}