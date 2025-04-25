#pragma once

#include <string>
using namespace std;
struct City {
    string name;
    int age;
    int area;
};

enum CompareCity { ByAge, ByArea, ByName };

bool compareCity(const City& a, const City& b, CompareCity type);
bool compareCityByAge(const City& a, const City& b);
bool compareCityByArea(const City& a, const City& b);
bool compareCityByName(const City& a, const City& b);
void printCity(City arr[], int n);

