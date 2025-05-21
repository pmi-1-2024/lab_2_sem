#pragma once
#include <string>
#include <vector>

using namespace std;

class Processor {
private:
    vector<char> data;

public:
    void setData(const vector<char>& input);
    const vector<char>& getData() const;


    void filterLetters();
    void toUpperCase();
};
