#include <iostream>
#include <vector>
#include "fileFuncs.h"
#include "processing.h"
#include "exceptions.h"
using namespace std;

int main() {
    try {
        vector<char> chars;
        read("input.txt", chars);

        vector<char> result = replace(chars);

        write("output.txt", result);
    }
    catch (const DataError& e) {
        cerr << "Data error: " << e.what() << endl;
        return 0;
    }
    catch (const FileError& e) {
        cerr << "File error: " << e.what() << endl;
        return 0;
    }
    catch (const exception& e) {
        cerr << "Other error: " << e.what() << endl;
        return 0;
    }
    catch (...) {
        cerr << "Unknown error" << endl;
        return 0;
    }

    return 0;
}