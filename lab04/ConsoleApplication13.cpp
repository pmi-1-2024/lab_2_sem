#include <iostream>
#include "Phone.h"
#include "Phone_Manager.h"

using namespace std;

int main() {
    Phone_Manager manager;
    manager.add(Phone("Iphone 12", "Apple", 1000));
    manager.add(Phone("Galaxy S21", "Samsung", 900));
    manager.add(Phone("Mi 11", "Xiaomi", 800));

    manager.show();
    cout << endl;

    manager.changePrice("Iphone 12", 1200);
    manager.remove(Phone("Galaxy S21", "Samsung", 900));

    manager.show();
    cout << endl;

    Phone* p = manager.find("Mi 11");
    if (p) cout << "Price of Mi 11: " << p->getPrice() << endl;

    return 0;
}
