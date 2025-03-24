#ifndef MPHONE_H
#define MPHONE_H

#include "phone.h"

class MobilePhone : virtual public Phone {
protected:
    string color;
    int storage;
public:
    virtual void print(ostream& out);
    virtual void input(istream& in);
    MobilePhone();
    virtual string get_type();
    virtual ~MobilePhone(){}
};

#endif
