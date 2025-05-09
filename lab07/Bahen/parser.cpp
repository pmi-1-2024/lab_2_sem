#include <iostream>
#include <typeinfo>
#include <fstream>
#include <sstream>
using namespace std;

#define WRITE(out, name) write((out), #name, (name))

int tabs = 0;

ostream& tab(ostream& out){return out<<"\t";}

void tabulate(ostream& out){
    for(int i =0; i < tabs; i ++) out << tab;
}
template <class T>
void write(ostream& out, string name, T val){
    tabulate(out);
    out <<"<"<<name<<">"<<val<<"</"<<name<<">"<<endl;
}
void header(ostream& out, string name){
    tabulate(out);
    out << "("<<name<<"){"<<endl;
    tabs++;
}
void ender(ostream& out){
    tabs--;
    tabulate(out);
    out <<"}";
}
void done(ostream& out){
    out << ";";
}
string get_object(ifstream& src){
    string res;
    getline(src, res, ';');
    return res;
}

string cut(string& data, int start, int end,int t_start,int t_end){

    string responce = data.substr(start+1,end-start-1) + " ";
    data = data.substr(0,t_start)+data.substr(t_end+1);
    return responce;
}
string cut(string& data, int start, int end){
    return cut(data,start,end,start,end);
}
string get_types(string& data){
    string types = "";
    int start, end;
    while(data.find('(') != string::npos){
        start = (int)data.find('(');
        end = (int)data.find(')');
        types += cut(data, start,end);
    }
    return types;
}

string get_values(string& data){
    string res = "", tag = "";
    int end, t_start, t_end;
    while(data.find('<') != string::npos){
        t_start = data.find('<');
        t_end = data.find('>');
        tag = data.substr(t_start+1,t_end-t_start-1);
        
        end = data.find("</"+tag+">");
        string val = cut(data,t_end,end,t_start,end+tag.length()+3);
        if(val.find("{")==string::npos)
            res += val+" ";
        else
            res += get_values(val)+" ";
        
    }
    return res;
}
