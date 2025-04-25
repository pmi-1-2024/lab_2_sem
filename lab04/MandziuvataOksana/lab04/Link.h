#pragma once
#include <iostream>

class Link {
public:
    Link* next;
    Link() : next(nullptr) {}
    Link(Link* l) : next(l) {}
    virtual ~Link() = default;
};