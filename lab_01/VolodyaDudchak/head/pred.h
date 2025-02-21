#include <bits/stdc++.h>
using namespace std;

ifstream in("in.txt");

class predmet{
    public:
    string name;
    int sem;
    int* marks;
    int n;
    predmet();
    predmet(int zp, string nm, int* maks);
    void inp();
    void out();
};