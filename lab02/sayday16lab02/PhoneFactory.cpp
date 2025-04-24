#include "PhoneFactory.h"
#include <string>
#include "MobilePhone.h"
#include "RadioPhone.h"
#include <iostream>

using namespace std;

Phone* PhoneFactory::createPhone(int type, istream& is) {
    switch (type) {
    case 2: {
        auto* mp = new MobilePhone();
        is >> *mp;
        return mp;
    }
    case 3: {
        auto* rp = new RadioPhone();
        is >> *rp;
        return rp;
    }
    default:
        cerr << "Unknown phone type: " << type << endl;
        return nullptr;
    }
}

