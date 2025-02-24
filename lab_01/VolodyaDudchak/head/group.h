#include <bits/stdc++.h>
#include "../sours/stud.cpp"
using namespace std;

class group{
    private:
    int numb;
    student* students;
    int sz;
    public:
    group();
    group(int nu, int s, student* stud);
    void change_Numb(int i);
    void add(student);
    void out();
    int getSz();
};