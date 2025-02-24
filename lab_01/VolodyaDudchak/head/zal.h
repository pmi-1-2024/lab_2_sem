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
    void inp();
    void out();
    int getZali();
    int getZaliSz();
    predmet getPred(int i);
};