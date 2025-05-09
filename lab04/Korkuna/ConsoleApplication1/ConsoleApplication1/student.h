#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
class Student {
public:
    int id;
    string name;
    int age;
    string group;

    Student();

    friend ostream& operator << (ostream& out, const Student& c);
    friend istream& operator >> (istream& in, Student& c);


};