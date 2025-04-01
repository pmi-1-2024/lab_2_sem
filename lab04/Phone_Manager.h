#pragma once
#include "Phone.h"
#include "List.h"

class Phone_Manager {
private:
    List<Phone> list;
public:
    void add(Phone phone) { list.push(phone); }
    void remove(Phone phone) { list.remove(phone); }
    void show() { list.show(); }

    Phone* find(string name) {
        Node<Phone>* temp = list.head;
        while (temp) {
            if (temp->data.getName() == name) return &temp->data;
            temp = temp->next;
        }
        return nullptr;
    }

    void changePrice(string name, double price) {
        Phone* temp = find(name);
        if (temp) temp->setPrice(price);
    }
};

