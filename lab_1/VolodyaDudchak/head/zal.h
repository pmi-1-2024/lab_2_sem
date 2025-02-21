#include <bits/stdc++.h>
#include "../sours/pred.cpp"
using namespace std;

class zalikov{
    public:
    int name;
    predmet* preds;
    int sz;
    zalikov();
    zalikov(int zp, int ct, predmet* pd);
    void inp();
    void out();
};