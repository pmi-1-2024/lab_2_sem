
#pragma once
#include <cctype>

class NotALetter {
public:
    bool operator()(char c) const {
        return !isalpha(static_cast<unsigned char>(c));
    }
};

class ToUpper {
public:
    char operator()(char c) const {
        return static_cast<char>(toupper(static_cast<unsigned char>(c)));
    }
};
