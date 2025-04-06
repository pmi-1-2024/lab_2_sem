#ifndef LINK_H
#define LINK_H

struct Link {
    Link* next;
    Link() : next(nullptr) {}
    virtual ~Link() {}
};

#endif