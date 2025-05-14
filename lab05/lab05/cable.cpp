#include "cable.h"

bool Cable::operator>(const Cable& other) const {
    return length > other.length;
}

ostream& operator<<(ostream& os, const Cable& cab) {
    return os << cab.type << " (" << cab.color << ", " << cab.length / 100.0 << "m)";
}