#include "processor.h"
#include "predicates.h"
#include <algorithm>
#include <cctype>

using namespace std;

void Processor::setData(const vector<char>& input) {
    data = input;
}

const vector<char>& Processor::getData() const {
    return data;
}


void Processor::filterLetters() {
    data.erase(remove_if(data.begin(), data.end(), NotALetter()), data.end());
}

void Processor::toUpperCase() {
    transform(data.begin(), data.end(), data.begin(), ToUpper());
}
