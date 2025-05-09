#include <iostream>
#include <fstream>
#include "phone.h"
#include "m_phone.h"
#include "r_phone.h"
#include "functions.h"
using namespace std;

int main() {
	int n = 10;
	int index = 0;
	int auto_size;
	Phone** phones = new Phone * [n];

	read("1.txt", phones, index);
	read("2.txt", phones, index);

	quick_sort(phones, 0, index - 1);

	write("out_1.txt", phones, index);

	Phone** auto_phones = has_auto(phones, index, auto_size);
	write("out_2.txt", auto_phones, auto_size);

	return 1;
}
