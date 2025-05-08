#include "person.h"
using namespace std;
struct Goods{
    string name;
    int amount;
    int price;
    bool fragile, medical;

    Goods(string n, int a, int pr, bool fr = false, bool md = false){
        name = n;
        amount = a;
        price = pr;
        fragile = fr;
        medical = md;
    }

    Goods(){
        name = "shtoto";
        amount = 0;
        price = 999;
        fragile = true;
        medical = true;
    }

    string get_type(){return "Goods";}
    
    void print(ostream& out){
        header(out,get_type());
        WRITE(out,name);
        WRITE(out,amount);
        WRITE(out,price);
        WRITE(out,fragile);
        WRITE(out,medical);
        ender(out);
    }

    friend ostream& operator <<(ostream& out, Goods& g){
        out << endl; 
        g.print(out);
        return out;
    }

    friend istream& operator >>(istream& inp, Goods& g){
        inp >> g.name >> g.amount >> g.price >> g.fragile >> g.medical;
        return inp;
    }
};