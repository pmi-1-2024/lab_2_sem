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
    int getSz();
    friend ostream& operator <<(ostream& out, group& a);
    friend istream& operator >>(istream& in, group& a);
    group(group& a);
	student& operator[](int);
    group& operator=(group& a);
    ~group(){
        delete[]students;
    }
};