#include "fileFuncs.h"
#include "exceptions.h"
#include <fstream>
#include <iterator>

bool read(string filename, vector<char>& data) {
    ifstream fin(filename);
    if (!fin) throw FileError("Failed to open file for reading: " + filename);

    int n;
    if (!(fin >> n)) throw DataError("First line must be an integer (number of characters).");
    fin.ignore();

    istream_iterator<char> it(fin), end;
    data.assign(it, end);

    if ((int)data.size() != n)
        throw DataError("Number of characters in file (" + to_string(data.size()) + ") does not match the declared count (" + to_string(n) + ").");

    return true;
}

bool write(string filename, vector<char>& data) {
    ofstream fout(filename);
    if (!fout) throw FileError("Failed to open file for writing: " + filename);

    fout << data.size() << endl;

    ostream_iterator<char> out(fout, "");
    copy(data.begin(), data.end(), out);

    return true;
}