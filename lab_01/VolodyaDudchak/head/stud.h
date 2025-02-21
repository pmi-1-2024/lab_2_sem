#include <bits/stdc++.h>
#include "../sours/zal.cpp"
#include "../sours/add.cpp"
using namespace std;


class student{
    public:
    string name;
    adres ad;
    int group;
    zalikov zali;
    student();
    student(string ne, int gp, adres add, zalikov zi);
    void inp();
    void out();
};