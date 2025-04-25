#pragma once
#include "special_transport.h"
#include "goods.h"
#include "person.h"
#include <fstream>
#include <string>
#include <iostream>
#include <stdexcept>

const int MAX_TRANSPORTS = 100;

int read_from_file(const string& filename, DefaultTransport** list) {
    ifstream in(filename);
    if (!in) {
        throw runtime_error("File could not be opened: " + filename);  
    }

    string transport_type, object_type;
    int count = 0;

    try {
        while (in >> transport_type >> object_type) {
            if (transport_type == "Transport") {
                if (object_type == "Goods") {
                    Goods g; double pr; string dest;
                    in >> g >> pr >> dest;
                    if (in.fail()) throw invalid_argument("Error reading Goods transport data.");
                    list[count++] = new Transport<Goods>(g, pr, dest);
                }
                else if (object_type == "Person") {
                    Person p; double pr; string dest;
                    in >> p >> pr >> dest;
                    if (in.fail()) throw invalid_argument("Error reading Person transport data.");
                    list[count++] = new Transport<Person>(p, pr, dest);
                }
            }
            else if (transport_type == "SpecialTransport") {
                if (object_type == "Goods") {
                    Goods g; double pr; string dest; bool cond;
                    in >> g >> pr >> dest >> cond;
                    if (in.fail()) throw invalid_argument("Error reading SpecialTransport Goods data.");
                    list[count++] = new SpecialTransport<Goods>(g, pr, dest, cond);
                }
                else if (object_type == "Person") {
                    Person p; double pr; string dest; bool cond;
                    in >> p >> pr >> dest >> cond;
                    if (in.fail()) throw invalid_argument("Error reading SpecialTransport Person data.");
                    list[count++] = new SpecialTransport<Person>(p, pr, dest, cond);
                }
            }
        }
    }
    catch (const exception& e) {
        cerr << "Error reading from file: " << e.what() << endl;
        return count;  
    }

    return count;
}

void print_all(DefaultTransport** list, int size) {
    try {
        for (int i = 0; i < size; ++i) {
            cout << i << ": ";
            cout << *list[i] << endl;
        }
    }
    catch (const exception& e) {
        cerr << "Error during printing transport: " << e.what() << endl;
    }
}

int sum_prices(DefaultTransport** list, int size) {
    int sum = 0;
    try {
        for (int i = 0; i < size; ++i) {
            sum += list[i]->get_price();
        }
    }
    catch (const exception& e) {
        cerr << "Error calculating total price: " << e.what() << endl;
    }
    return sum;
}

void apply_discounts(DefaultTransport** list, int size) {
    try {
        for (int i = 0; i < size; ++i) {
            list[i]->apply_discount();
        }
    }
    catch (const exception& e) {
        cerr << "Error applying discounts: " << e.what() << endl;
    }
}

DefaultTransport* find_most_expensive(DefaultTransport** list, int size) {
    if (size == 0) return nullptr;

    int max_idx = 0;
    try {
        for (int i = 1; i < size; ++i) {
            if (list[i]->get_price() > list[max_idx]->get_price()) {
                max_idx = i;
            }
        }
    }
    catch (const exception& e) {
        cerr << "Error finding the most expensive transport: " << e.what() << endl;
    }

    return list[max_idx];
}

void update_destination(DefaultTransport** list, int size, int index, const string& new_dest) {
    try {
        if (index >= 0 && index < size) {
            list[index]->set_dest(new_dest);
        }
        else {
            throw out_of_range("Invalid index for updating destination.");
        }
    }
    catch (const exception& e) {
        cerr << "Error updating destination: " << e.what() << endl;
    }
}

void filter_by_type(DefaultTransport** list, int size, const string& type) {
    try {
        for (int i = 0; i < size; ++i) {
            if (list[i]->get_object_type() == type) {
                cout << *list[i] << endl;
            }
        }
    }
    catch (const exception& e) {
        cerr << "Error during filtering by type: " << e.what() << endl;
    }
}