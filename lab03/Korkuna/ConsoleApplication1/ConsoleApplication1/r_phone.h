#ifndef RPHONE_H
#define RPHONE_H

#include "phone.h"

class RadioPhone : virtual public Phone {
protected:
    int radius;
    bool is_auto;
public:
    virtual void print(ostream& out);
    virtual void input(istream& in);
    RadioPhone();
    bool has_auto();
    virtual string get_type();
    virtual ~RadioPhone(){}
};

#endif
