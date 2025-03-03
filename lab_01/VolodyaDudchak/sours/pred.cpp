#include <bits/stdc++.h>
#include "../head/pred.h"
using namespace std;

predmet::predmet(){
    name = "", sem = 0;
}
predmet::predmet(int zp, string nm, int* maks)
{
    sem = zp, marks = maks, name = nm;
}


string predmet::getName(){
    return name;
}

int predmet::getSem(){
    return sem;
}

int* predmet::getMarks(){
    return marks;
}

int predmet::getSz(){
    return n;
}

istream& operator >> (istream& in, predmet& a){
    in >> a.name >> a.sem >> a.n;
    a.marks = new int(a.n);
    for(int i = 0; i < a.n; i++)
        in >> a.marks[i];
    return in;
}
ostream& operator << (ostream& out, predmet& a){
    out << "Predmet - "<<a.name << " semester - " << a.sem << " marks  - ";
    for(int i = 0; i < a.n; i++)
        out << a.marks[i] << ' ';
    out << endl;
    return out;
}