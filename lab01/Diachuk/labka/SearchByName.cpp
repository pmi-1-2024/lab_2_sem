#include "SearchByName.h"
#include <iostream>

using namespace std;

void searchByName(Student students[], int count, const string& name) {
    for (int i = 0; i < count; i++) {
        if (students[i].name == name) {
            students[i].print();
        }
    }
}
