#include "special_transport.h"

using namespace std;

void read(string src, DefaultTransport ** list){
    ifstream file(src);
    string types, val, type, container;
    int i = 0;
    string object;
    while(!file.eof()){

        object = get_object(file);
        types = get_types(object);
        val = get_values(object);
        stringstream type_inp(types);
        stringstream val_inp(val);

        type_inp >> type >> container;
        DefaultTransport * new_e;
        if(type == "Transport"){
            if(container == "Goods") new_e = new Transport<Goods>();
            else if(container == "Person") new_e = new Transport<Person>();
        }
        else if(type == "SpecialTransport"){
            if(container == "Goods")new_e = new SpecialTransport<Goods>();
            else if(container == "Person") new_e = new SpecialTransport<Person>();
        }
        val_inp >> *new_e;
        list[i] = new_e;
        i++;
    }
}

void save(DefaultTransport ** list, int n, string src){
    ofstream out(src);
    for(int i = 0; i < n; i++) out << *list[i];
}

int sum_price(DefaultTransport ** list, int n){
    int res = 0;
    for(int i = 0; i < n; i++)res += list[i]->get_price();
    return res;
} 

void discount(DefaultTransport ** list, int n){
    for(int i = 0; i < n; i++) list[i]->get_discout();
}

DefaultTransport ** type_filter(DefaultTransport ** list, int& size, string type){
    int k = 0;
    DefaultTransport ** res = new DefaultTransport*[size];
    for(int i = 0; i < size; i++)
        if(list[i]->get_object_type() == type){
            res[k] = list[i];    
            k++;
        }
    size = k;
    return res;
}