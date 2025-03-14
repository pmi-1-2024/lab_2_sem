#include "SearchByGroup.h"
#include <iostream>

using namespace std;

void searchByGroup(Student students[], int count, const string& group) {
    for (int i = 0; i < count; i++) {
        if (students[i].group == group) {
            students[i].print();
        }
    }
}
