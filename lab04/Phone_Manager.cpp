#include "Phone_Manager.h"

void Phone_Manager::add(Phone phone) {
    list.push(phone);
}

void Phone_Manager::remove(Phone phone) {
    list.remove(phone);
}

void Phone_Manager::show() {
    list.show();
}

Phone* Phone_Manager::find(string name) {
    Node<Phone>* temp = list.head;
    while (temp) {
        if (temp->data.getName() == name)
            return &temp->data;
        temp = temp->next;
    }
    return nullptr;
}

void Phone_Manager::changePrice(string name, double price) {
    Phone* temp = find(name);
    if (temp) temp->setPrice(price);
}
