#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <string>
#include <exception>

using namespace std;

bool isLetter(char c) {
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}


int main(int argc, char** argv) try
{
	string inputFileName = "input.txt";
	string outputFileName = "output.txt";
	if (argc > 1)
	{
		inputFileName = argv[1];
	}
	if (argc > 2)
	{
		outputFileName = argv[2];
	}

	ifstream input(inputFileName);
	input.exceptions(ifstream::failbit | ifstream::badbit);
	ofstream output(outputFileName);
	output.exceptions(ofstream::failbit | ofstream::badbit);
	istream_iterator<string> in(input), end;
	vector<char> v;
	if (in == end)
	{
		throw runtime_error("No words in the file");
	}
	string word = *in;
	copy(word.begin(), word.end(), back_inserter(v));
	v.erase(remove_if(v.begin(), v.end(), [](char c) { return !isLetter(c); }), v.end());
	transform(v.begin(), v.end(), v.begin(), [](char c) { return toupper(c); });
	ostream_iterator<char> out(output);
	copy(v.begin(), v.end(), out);
	input.close();
	output.close();

}
catch (const ifstream::failure& e)
{
	cerr << "Exception opening/reading file\n";
}
catch (const runtime_error& e)
{
	cerr << "Runtime error: " << e.what() << endl;
}
catch (const exception& e)
{
	cerr << "Exception: " << e.what() << endl;
}
catch (...)
{
	cerr << "Unknown exception\n";
}
