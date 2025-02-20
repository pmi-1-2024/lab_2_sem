#include <bits/stdc++.h>
#include "pred.h"
using namespace std;

class zalikov{
    public:
    int name;
    predmet* preds;
    int sz;
    zalikov(){
        sz = 0, name = 0, preds = new predmet[0];
    }
    zalikov(int zp, int ct, predmet* pd)
    {
        sz = zp, name = ct, preds = pd;
    }
    void inp()
    {
        in >> name>> sz;
        preds = new predmet[sz];
        for(int i = 0; i < sz;i++)
            preds[i].inp();
    }
    void out()
    {
        cout << "Zalick: ";
        cout << name << ' ' << sz << ' ' << endl;
        for(int i = 0; i < sz;i++)
            preds[i].out();
    }
};