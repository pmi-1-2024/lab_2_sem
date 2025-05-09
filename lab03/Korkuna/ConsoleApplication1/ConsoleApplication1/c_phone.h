#ifndef CPHONE_H
#define CPHONE_H
#include "r_phone.h"
#include "m_phone.h"
class ComboPhone: public MobilePhone, public RadioPhone{
public:
    virtual void print(ostream& out);
    virtual void input(istream& out);
    ComboPhone();
    virtual string get_type();
    ~ComboPhone(){}
};
#endif
