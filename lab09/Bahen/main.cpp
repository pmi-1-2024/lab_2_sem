#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <fstream>

using namespace std;
int main()
{
    try{
    vector<char> v;
    int counter=0;

    ifstream inp("inp.txt");
    if(! inp.is_open()) throw "Cannot open file";
    ofstream out("out.txt");

    istream_iterator<char> cin_it(inp);
    istream_iterator<char> eos;

    ostream_iterator<char> cout_it(out, " ");
    ostream_iterator<int> cout_int(out," ");

    for_each(cin_it, eos, [&](char a) {
        if (a != 'p') v.push_back(a);  
        if(a == 'x') counter++;
    });
    v.push_back('\n');
    copy(v.begin(), v.end(), cout_it);
    out<<counter;
    inp.close();
    out.close();
    return 0;
    }
    catch(const char* e){cout << e;}
}