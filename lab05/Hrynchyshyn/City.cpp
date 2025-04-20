#include "city.h"
#include <iostream>

bool compareCity(const City& a, const City& b, CompareCity type) {
    switch (type) {
    case ByAge: return a.age < b.age;
    case ByArea: return a.area < b.area;
    case ByName: return a.name < b.name;
    default: return false;
    }
}

bool compareCityByAge(const City& a, const City& b) {
    return compareCity(a, b, ByAge);
}

bool compareCityByArea(const City& a, const City& b) {
    return compareCity(a, b, ByArea);
}

bool compareCityByName(const City& a, const City& b) {
    return compareCity(a, b, ByName);
}

void printCity(City arr[], int n) {
    for (int i = 0; i < n; i++)
    cout << "(" << arr[i].name << ", " << arr[i].age << ", " << arr[i].area << ") ";
    cout << endl;
}