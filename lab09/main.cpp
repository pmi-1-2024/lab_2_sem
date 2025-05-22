#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <string>

using namespace std;


struct ReplaceExclamWithDot {
    char operator()(char c) const {
        return (c == '!') ? '.' : c;
    }
};


struct ConsecutiveDots {
    bool operator()(char a, char b) const {
        return a == '.' && b == '.';
    }
};


struct DotToTripleDot {
    vector<char>& output;
    DotToTripleDot(vector<char>& out) : output(out) {}

    void operator()(char c) {
        if (c == '.') {
            output.insert(output.end(), { '.', '.', '.' });
        }
        else {
            output.push_back(c);
        }
    }
};


struct DotGroupToTripleDot {
    vector<char>& output;
    bool inDotGroup = false;

    DotGroupToTripleDot(vector<char>& out) : output(out) {}

    void operator()(char c) {
        if (c == '.') {
            if (!inDotGroup) {
                output.insert(output.end(), { '.', '.', '.' });
                inDotGroup = true;
            }
        }
        else {
            inDotGroup = false;
            output.push_back(c);
        }
    }
};


void process_a(vector<char>& data) {
    transform(data.begin(), data.end(), data.begin(), ReplaceExclamWithDot());
}


void process_b(vector<char>& data) {
    vector<char> result;
    for_each(data.begin(), data.end(), DotToTripleDot(result));
    data = result;
}


void process_c(vector<char>& data) {
    vector<char> result;
    unique_copy(data.begin(), data.end(), back_inserter(result), ConsecutiveDots());
    data = result;
}


void process_d(vector<char>& data) {
    vector<char> result;
    for_each(data.begin(), data.end(), DotGroupToTripleDot(result));
    data = result;
}

int main() {
    ifstream inFile("input.txt");
    ofstream outFile("output2.txt");

    if (!inFile || !outFile) {
        cerr << "file kaput" << endl;
        return 1;
    }

    
    char mode;
    inFile >> mode;
    inFile.ignore(); 

   
    istream_iterator<char> inputIt(inFile), eof;
    vector<char> data(inputIt, eof);

    
    switch (mode) {
    case 'a': process_a(data); break;
    case 'b': process_b(data); break;
    case 'c': process_c(data); break;
    case 'd': process_d(data); break;
    default:
        cerr << "None: " << mode << endl;
        return 2;
    }

    
    ostream_iterator<char> outputIt(outFile, "");
    copy(data.begin(), data.end(), outputIt);

    return 0;
}
