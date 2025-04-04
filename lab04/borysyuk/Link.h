#pragma once
#include "Address.h"
struct Link {
    Link* next;
    virtual ~Link() {}
protected:
    Link() : next(0) {}
};

struct Address_link : Link {
    Address data;

    Address_link(const Address& a) :data(a) {}
};