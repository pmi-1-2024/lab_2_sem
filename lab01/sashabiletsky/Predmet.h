#ifndef PREDMET_H
#define PREDMET_H

#include <string>
using namespace std;

class Predmet {
public:
    string name;
    int semester;
    int grade;

    Predmet(string n, int s, int g) : name(n), semester(s), grade(g) {}
    Predmet() {}
};

#endif 
