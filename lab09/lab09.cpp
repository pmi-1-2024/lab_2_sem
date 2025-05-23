#include <iostream>
#include <vector>
#include "fileFuncs.h"
#include "processing.h"
#include "exceptions.h"
using namespace std;

int main() {
    vector<char> chars;
    try {
        if (!read("input.txt", chars)) {
            cerr << "Reading error!" << endl;
            return 1;
        }
    }
    catch (const exception& e) {
        cerr << "Read error: " << e.what() << endl;
        return 1;
    }

    vector<char> result = replace(chars);

    try {
        if (!write("output.txt", result)) {
            cerr << "Writing error!" << endl;
            return 2;
        }
    }
    catch (const exception& e) {
        cerr << "Write error: " << e.what() << endl;
        return 2;
    }

    return 0;
}