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
void predmet::inp()
{
    in >> name >> sem >> n;
    marks = new int(n);
    for(int i = 0; i < n; i++)
        in >> marks[i];
}
void predmet::out()
{
    cout << "Predmet - "<<name << " semester - " << sem << " marks  - ";
    for(int i = 0; i < n; i++)
        cout << marks[i] << ' ';
    cout << endl;
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