#include <iostream>
#include "special_transport.h"
using namespace std;
struct Person{
    string name;
    int age;

    Person(string n, int a){
        name = n;
        age = a;
    }
    Person(){
        name = "Akakiy";
        age = -3;
    }
    string get_type(){return "Person";}
    void print(ostream& out){
        header(out,get_type());
        WRITE(out,name);
        WRITE(out,age);
        ender(out);
    }
    friend ostream& operator <<(ostream& out, Person& p){
        out << endl; 
        p.print(out);
        return out;
    }
    friend istream& operator >>(istream& inp, Person& p){
        inp >> p.name >> p.age;
        return inp;
    }
};
