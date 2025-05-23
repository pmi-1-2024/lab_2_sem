#include "processing.h"
#include "calc.h"
#include <string>
#include <iterator>

vector<char> replace(vector<char>& input) {
    vector<char> result;
    auto it = input.begin();

    while (it != input.end()) {
        IsChildAt pred;
        pred.pos = it;
        pred.end = input.end();

        if (pred(it)) {
            string rep = "children";
            copy(rep.begin(), rep.end(), back_inserter(result));
            advance(it, 5);
        }
        else {
            result.push_back(*it);
            ++it;
        }
    }

    return result;
}