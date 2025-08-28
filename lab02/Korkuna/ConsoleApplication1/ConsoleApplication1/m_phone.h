#ifndef MPHONE_H
#define MPHONE_H

#include "phone.h"

class MobilePhone : public Phone {
private:
    string color;
    int storage;
public:
    virtual void print(ostream& out);
    virtual void input(istream& in);
    MobilePhone();
    virtual string get_type();
    ~MobilePhone(){}
};

#endif
