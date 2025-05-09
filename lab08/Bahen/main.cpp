#include <iostream>
#include <tuple>
#include <vector>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;

enum Bill{
    GAS,
    WATER
};

vector<tuple<int, string, int ,int>> read(string src){
    vector<tuple<int, string, int ,int>> res;
    ifstream file(src);
    if(! file.is_open()) throw "File cannot be opened";
    while(! file.eof()){
        tuple<int, string, int ,int> bill;
        file >> get<0>(bill);
        file >> get<1>(bill);
        file >> get<2>(bill);
        file >> get<3>(bill);
        res.push_back(bill);
    }
    file.close();
    return res;
}

void write(string src, vector<tuple<int, string, int ,int>> arr){
    ofstream file(src);
    for(auto bill: arr){
        file << get<0>(bill) << " " << get<1>(bill) << " " << get<2>(bill) << " " << get<3>(bill) << endl;
    }
    file.close();
}

template<int T, bool rev = false>
bool comp(tuple<int, string, int ,int> a, tuple<int, string, int ,int> b){
    bool res  = get<T>(a) < get<T>(b);
    if(rev) res = ! res;
    return res;
}

int main(){
    try{
        vector<tuple<int, string, int ,int>> bills;
        bills = read("inp.txt");
        sort(bills.begin(), bills.end(), comp<0>);
        auto it = find_if(bills.begin(), bills.end(), [](const tuple<int, string, int ,int> & s){ return get<0>(s) == WATER;});
        sort(bills.begin(),it,comp<1>);
        sort(it,bills.end(),comp<3,true>);

        for(auto bill: bills){
            cout << get<0>(bill) << " " << get<1>(bill) << " " << get<2>(bill) << " " << get<3>(bill) << endl;
        }
        write("gas.txt",vector<tuple<int, string, int ,int>>(bills.begin(),it));
        write("water.txt",vector<tuple<int, string, int ,int>>(it,bills.end()));
    }
    catch(const char* exception){
        cerr << "Error: " << exception << endl;
    }
}