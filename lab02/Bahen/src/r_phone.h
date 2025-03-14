#ifndef RPHONE_H
#define RPHONE_H

#include "phone.h"

class RadioPhone : public Phone {
private:
    int radius;
    bool is_auto;
public:
    virtual void print(ostream& out);
    virtual void input(istream& out);
    RadioPhone();
    bool has_auto();
    virtual string get_type();
    ~RadioPhone(){}
};

#endif
