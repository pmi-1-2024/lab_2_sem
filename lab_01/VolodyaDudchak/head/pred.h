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
    predmet(predmet& a);
	int& operator[](int);
    predmet(int zp, string nm, int* maks);
    int getSem();
    string getName();
    int* getMarks();
    int getSz();
    friend ostream& operator <<(ostream& out, predmet& a);
    friend istream& operator >>(istream& in, predmet& a);
    predmet& operator=(predmet& a);
    ~predmet(){
        delete[]marks;
    }
};