#include "SearchByGrade.h"
#include <iostream>

using namespace std;

void searchByGrade(Student students[], int count, double grade) {
    for (int i = 0; i < count; i++) {
        if (students[i].grade == grade) {
            students[i].print();
        }
    }
}
