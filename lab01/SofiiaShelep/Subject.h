#pragma once
#include <string>
using namespace std;

class Subject
{
private:
    string name;
    int semester;
    int grade;

public:
    Subject();
    Subject(string n, int s, int g);

    void setName(string n);
    void setSemester(int s);
    void setGrade(int g);

    string getName() const;
    int getSemester() const;
    int getGrade() const;

    friend ostream& operator<<(ostream& os, const Subject& sub);
    friend istream& operator>>(istream& is, Subject& sub);
};