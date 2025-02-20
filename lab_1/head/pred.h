#include <bits/stdc++.h>
using namespace std;

ifstream in("in.txt");

class predmet{
    public:
    string name;
    int sem;
    int* marks;
    int n;
    predmet(){
        name = "", sem = 0;
    }
    predmet(int zp, string nm, int* maks)
    {
        sem = zp, marks = maks, name = nm;
    }
    void inp()
    {
        in >> name >> sem >> n;
        marks = new int(n);
        for(int i = 0; i < n; i++)
            in >> marks[i];
    }
    void out()
    {
        cout << "Predmet - "<<name << " semester - " << sem << " marks  - ";
        for(int i = 0; i < n; i++)
            cout << marks[i] << ' ';
        cout << endl;
    }
};