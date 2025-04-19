#ifndef PHONE_FACTORY_H
#define PHONE_FACTORY_H

#include <iostream>
#include "Phone.h"
#include "MobilePhone.h"
#include "RadioPhone.h"

class PhoneFactory {
public:
    static Phone* createPhone(int type, istream& is);
};
#endif 
