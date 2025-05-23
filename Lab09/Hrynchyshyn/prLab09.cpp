#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>
#include <string>

using namespace std;

class IsONorNO {
public:
	bool operator()(vector<char>::const_iterator it) const {
		return (*it == 'o' && *(it + 1) == 'n') || (*it == 'n' && *(it + 1) == 'o');
	}
};

bool check_condition_e(const vector<char>& s) {
	for (size_t i = 1; i + 2 < s.size(); ++i) {
		for (size_t j = i + 1; j + 1 < s.size(); ++j) {
			if (s[j] == s[i + 1] && s[i] == s[j + 1]) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");

	if (!in || !out) {
		cerr << "Cannot open input or output file.\n";
		return 1;
	}

	istream_iterator<char> it(in), eos;
	vector<char> chars(it, eos);

	auto excl_it = find(chars.begin(), chars.end(), '!');
	if (excl_it == chars.end()) {
		out << "Error: No exclamation mark found!\n";
		return 1;
	}

	vector<char> before_excl;
	copy(chars.begin(), excl_it, back_inserter(before_excl));
	bool has_on_no = false;
	IsONorNO pred;
	for (auto it = before_excl.begin(); it + 1 != before_excl.end(); ++it) {
		if (pred(it)) {
			has_on_no = true;
			break;
		}
	}

	bool has_adjacent_duplicates = adjacent_find(before_excl.begin(), before_excl.end()) != before_excl.end();
	bool condition_e = check_condition_e(before_excl);


	ostream_iterator<string> out_it(out, "\n");
	*out_it++ = string("(g) Is there a pair \"on\" or \"no\"? ") + (has_on_no ? "Yes" : "No");
	*out_it++ = string("(d) Are there adjacent identical characters? ") + (has_adjacent_duplicates ? "Yes" : "No");
	*out_it++ = string("(e) Do there exist i, j such that s[j] == s[i+1] and s[i] == s[j+1]? ") + (condition_e ? "Yes" : "No");


	return 0;
}
