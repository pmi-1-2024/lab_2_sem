#ifndef PHONEMANAGER_H
#define PHONEMANAGER_H

#include "PhoneList.h"
#include <fstream>

class PhoneManager {
private:
    Phone_List list;
public:
    void add(Phone* p) {
        list.push(p);
    }

    void removeByName(const string& name) {
        Phone_Link* target = list.findByName(name);
        if (target) {
            Link* removed = list.remove(target);
            delete ((Phone_Link*)removed)->data;
            delete removed;
        }
    }

    void search(const string& name, ostream& out) {
        Phone_Link* found = list.findByName(name);
        if (found)
            out << *(found->data);
        else
            out << "Not found" << endl;
    }

    void printAll(ostream& out) {
        list.printAll(out);
    }
};

#endif
