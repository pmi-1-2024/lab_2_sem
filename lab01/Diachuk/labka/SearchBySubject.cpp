#include "SearchBySubject.h"
#include <iostream>

using namespace std;

void searchBySubject(Student students[], int count, const string& subject) {
    for (int i = 0; i < count; i++) {
        if (students[i].subject == subject) {
            students[i].print();
        }
    }
}
