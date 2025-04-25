#pragma once
#include "special_transport.h"
#include"goods.h"
#include"person.h"
#include <fstream>
#include <string>

const int MAX_TRANSPORTS = 100;

int read_from_file(const string& filename, DefaultTransport** list) {
    ifstream in(filename);
    string transport_type, object_type;
    int count = 0;

    while (in >> transport_type >> object_type) {
        if (transport_type == "Transport") {
            if (object_type == "Goods") {
                Goods g; double pr; string dest;
                in >> g >> pr >> dest;
                list[count++] = new Transport<Goods>(g, pr, dest);
            }
            else if (object_type == "Person") {
                Person p; double pr; string dest;
                in >> p >> pr >> dest;
                list[count++] = new Transport<Person>(p, pr, dest);
            }
        }
        else if (transport_type == "SpecialTransport") {
            if (object_type == "Goods") {
                Goods g; double pr; string dest; bool cond;
                in >> g >> pr >> dest >> cond;
                list[count++] = new SpecialTransport<Goods>(g, pr, dest, cond);
            }
            else if (object_type == "Person") {
                Person p; double pr; string dest; bool cond;
                in >> p >> pr >> dest >> cond;
                list[count++] = new SpecialTransport<Person>(p, pr, dest, cond);
            }
        }
    }

    return count;
}

void print_all(DefaultTransport** list, int size) {
    for (int i = 0; i < size; ++i) {
        cout << i << ": ";
        cout << *list[i] << endl;
    }
}

int sum_prices(DefaultTransport** list, int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) sum += list[i]->get_price();
    return sum;
}

void apply_discounts(DefaultTransport** list, int size) {
    for (int i = 0; i < size; ++i) list[i]->apply_discount();
}

DefaultTransport* find_most_expensive(DefaultTransport** list, int size) {
    if (size == 0) return nullptr;
    int max_idx = 0;
    for (int i = 1; i < size; ++i)
        if (list[i]->get_price() > list[max_idx]->get_price())
            max_idx = i;
    return list[max_idx];
}

void update_destination(DefaultTransport** list, int size, int index, const string& new_dest) {
    if (index >= 0 && index < size) list[index]->set_dest(new_dest);
}

void filter_by_type(DefaultTransport** list, int size, const string& type) {
    for (int i = 0; i < size; ++i)
        if (list[i]->get_object_type() == type)
            cout << *list[i] << endl;
}