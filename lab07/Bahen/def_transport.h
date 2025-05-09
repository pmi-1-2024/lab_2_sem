#include <iostream>
#include <fstream>
#include <sstream>
#include "parser.cpp"
using namespace std;
class DefaultTransport{
    protected:
        double price;
        string destination;
    public:
        DefaultTransport(){
            price = 666.0;
            string destination = "tuda";
        }
    
        DefaultTransport(double pr, string dest){
            if(pr < 0) throw "Price cannot be a negative number";
            price = pr;
            destination = dest;
        }
    
        virtual string get_type() = 0;
        virtual string get_object_type() = 0;
        void set_dest(string dest){
            destination = dest;
        }
        int get_price(){return price;}
        virtual void get_discout(){
            price -= price > 1000 ? price*0.1 : 0;
        }
    
        virtual void print(ostream& out){
            header(out,get_type());
            WRITE(out,price);
            WRITE(out,destination);
        }
        virtual void input(istream& inp){
            inp >> price >> destination;
            if(price < 0) throw "Price cannot be a negative number";
        }
        friend ostream& operator <<(ostream& out, DefaultTransport& t){
            out << endl;
            t.print(out);
            ender(out);
            done(out);
            return out;
        }
        friend istream& operator >>(istream& inp, DefaultTransport& t){
            t.input(inp);
            return inp;
        }
    };