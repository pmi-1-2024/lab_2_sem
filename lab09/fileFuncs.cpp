#include "fileFuncs.h"
#include <fstream>
#include <iterator>

bool read(string filename, vector<char>& data) {
    ifstream fin(filename);
    if (!fin) return false;

    int n;
    fin >> n;
    fin.ignore();

    istream_iterator<char> it(fin), end;
    data.assign(it, end);

    return true;
}

bool write(string filename, vector<char>& data) {
    ofstream fout(filename);
    if (!fout) return false;

    ostream_iterator<char> out(fout, "");
    copy(data.begin(), data.end(), out);

    return true;
}