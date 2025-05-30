#pragma once
#include <vector>
using namespace std;

struct IsChildAt {
    vector<char>::iterator pos;
    vector<char>::iterator end;

    bool operator()(vector<char>::iterator it);
};