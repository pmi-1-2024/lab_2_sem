#include <bits/stdc++.h>
#include "../head/zal.h"

    zalikov::zalikov(){
        sz = 0, name = 0, preds = new predmet[0];
    }
    zalikov::zalikov(int zp, int ct, predmet* pd)
    {
        sz = zp, name = ct, preds = pd;
    }
    void zalikov::inp()
    {
        in >> name>> sz;
        preds = new predmet[sz];
        for(int i = 0; i < sz;i++)
            preds[i].inp();
    }
    void zalikov::out()
    {
        cout << "Zalick: ";
        cout << name << ' ' << sz << ' ' << endl;
        for(int i = 0; i < sz;i++)
            preds[i].out();
    }