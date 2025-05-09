#include "transport.h"
using namespace std;
template <class T>
class SpecialTransport: public Transport<T>{
    bool super_conditions;
public:
    SpecialTransport(T ob, double pr, string dest, bool super):Transport<T>(ob,pr,dest){
        super_conditions = super;
    }
    SpecialTransport():Transport<T>(){
        super_conditions = false;
    }

    virtual string get_type(){return "SpecialTransport";}

    void print(ostream & out){
        Transport<T>::print(out);
        WRITE(out,super_conditions);
    }

    virtual void input(istream& inp){
        Transport<T>::input(inp);
        inp >> super_conditions;
    }
    virtual void get_discout(){
        this->price -= this->price > 1000 ? this->price*0.1 : 0 + super_conditions ? this->price*0.05 : this->price*0.1;
    }
};