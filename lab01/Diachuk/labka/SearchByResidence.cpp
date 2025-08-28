#include "SearchByResidence.h"
#include <iostream>

using namespace std;

void searchByResidence(Student students[], int count, const string& residence) {
    for (int i = 0; i < count; i++) {
        if (students[i].residence == residence) {
            students[i].print();
        }
    }
}
