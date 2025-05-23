#include <iostream>
#include <vector>
#include "fileFuncs.h"
#include "processing.h"
using namespace std;

int main() {
    vector<char> chars;
    if (!read("input.txt", chars)) {
        cerr << "Reading error!" << endl;
        return 1;
    }

    vector<char> result = replace(chars);

    if (!write("output.txt", result)) {
        cerr << "Writing error!" << endl;
        return 2;
    }

    return 0;
}