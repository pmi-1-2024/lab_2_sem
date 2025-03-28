#include <bits/stdc++.h>
#include "../sours/zal.cpp"
#include "../sours/add.cpp"
using namespace std;


class student{
    private:
    string name;
    adres ad;
    int group;
    zalikov zali;
    public:
    student();
    student(string ne, int gp, adres add, zalikov zi);
    zalikov getZali();
    string getName();
    adres getAd();
    int getGroup();
    friend ostream& operator <<(ostream& out, student& a);
    friend istream& operator >>(istream& in, student& a);
};