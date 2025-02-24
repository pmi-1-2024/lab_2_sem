#include <bits/stdc++.h>
using namespace std;

ifstream in("in.txt");

class predmet{
    private:
    string name;
    int sem;
    int* marks;
    int n;
    public:
    predmet();
    predmet(int zp, string nm, int* maks);
    void inp();
    void out();
    int getSem();
    string getName();
    int* getMarks();
    int getSz();
};