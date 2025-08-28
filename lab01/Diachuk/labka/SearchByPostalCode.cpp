#include "SearchByPostalCode.h"
#include <iostream>

using namespace std;

void searchByPostalCode(Student students[], int count, const string& postal_code) {
    for (int i = 0; i < count; i++) {
        if (students[i].postal_code == postal_code) {
            students[i].print();
        }
    }
}
