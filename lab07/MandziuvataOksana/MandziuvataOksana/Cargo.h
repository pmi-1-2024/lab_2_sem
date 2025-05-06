#ifndef CARGO_H
#define CARGO_H

#include <iostream>
#include <string>

class Cargo {
private:
    std::string type;

public:
    Cargo() : type("Unknown") {}
    Cargo(std::string t) : type(t) {}

    std::string getType() const { return type; }
    void setType(const std::string& t) { type = t; }

    friend std::istream& operator>>(std::istream& in, Cargo& cargo) {
        in >> cargo.type;
        return in;
    }

    friend std::ostream& operator<<(std::ostream& out, const Cargo& cargo) {
        out << cargo.type;
        return out;
    }
};

#endif
