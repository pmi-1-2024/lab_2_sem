#include "def_transport.h"
using namespace std;
template <class T>
class Transport: public DefaultTransport{
protected:
    T object;
public:
    Transport(T ob, double pr, string dest):DefaultTransport(pr,dest){
        object = ob;
    }

    Transport():DefaultTransport(){
        object = T();
    }
    virtual string get_type(){return "Transport";}
    T get_object(){return object;}
    string get_object_type(){return object.get_type();}
    virtual void print(ostream& out){
        DefaultTransport::print(out);
        WRITE(out,object);
    }
    virtual void input(istream& inp){
        DefaultTransport::input(inp);
        inp >> object;
    }
    virtual void get_discout(){
        price -= price > 1000 ? price*0.1 : 0;
    }
};