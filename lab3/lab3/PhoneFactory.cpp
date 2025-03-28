#include "PhoneFactory.h"
#include "MegaPhone.h"
#include <string>
//Phone* createPhone(istream& in) {
//    int type;
//    if (!(in >> type)) {
//        //cerr << "Failed to read phone type.\n";
//        return nullptr;
//    }
//
//    string name, brand;
//    double price;
//    if (!(in >> name >> brand >> price)) {
//        cerr << "Failed to read phone data.\n";
//        return nullptr;
//    }
//
//    if (type == 2) {
//        string color;
//        int memory;
//        if (!(in >> color >> memory)) {
//            cerr << "Failed to read mobile phone details.\n";
//            return nullptr;
//        }
//        return new MobilePhone(name, brand, price, color, memory);
//    }
//    else if (type == 3) {
//        double range;
//        bool answeringMachine;
//        if (!(in >> range >> answeringMachine)) {
//            cerr << "Failed to read radio phone details.\n";
//            return nullptr;
//        }
//        return new RadioPhone(name, brand, price, range, answeringMachine);
//    }
//    else if (type == 4) {  
//        string color;
//        int memory;
//        double range;
//        bool answeringMachine;
//        if (!(in >> color >> memory >> range >> answeringMachine)) {
//            cerr << "Failed to read mega phone details.\n";
//            return nullptr;
//        }
//        return new MegaPhone(name, brand, price, color, memory, range, answeringMachine);
//    }
//    else {  
//        cerr << "Unknown phone type: " << type << endl;
//        return nullptr;
//    }
//}