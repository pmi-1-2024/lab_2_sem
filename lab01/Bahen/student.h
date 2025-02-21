#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>

#include <string>
#include "adress.h"
#include "zalicovca.h"

using namespace std;

class  Student {
private:
	string name;
	Adress adr;
	string group;
	Zalicovca zalicovca;
public:
    Student() {
        name = "";
        group = "";
    }
    string get_name();
    string get_zip();
    string get_group();
    string get_z_id();
    bool is_in_subjects(string sub);
    friend ostream& operator << (ostream& out, const Student& c);
    friend istream& operator >> (istream& in, Student& c);
   
};
#endif
