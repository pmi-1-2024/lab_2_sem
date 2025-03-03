#include <bits/stdc++.h>
#include "../sours/pred.cpp"
using namespace std;

class zalikov{
    private:
    int name;
    predmet* preds;
    int sz;
    public:
    zalikov();
    zalikov(int zp, int ct, predmet* pd);
    int getZali();
    int getZaliSz();
    predmet getPred(int i);
    friend ostream& operator <<(ostream& out, zalikov& a);
    friend istream& operator >>(istream& in, zalikov& a);
};