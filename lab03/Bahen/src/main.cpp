#include <iostream>
#include <fstream>
#include "phone.h"
#include "m_phone.h"
#include "r_phone.h"
#include "c_phone.h"
#include "functions.h"
using namespace std;

int main() {
	int n = 10;
	int index = 0;
	Phone ** phones = new Phone*[n];

	read("data.txt", phones, index);
	search(phones,index);

	return 1;
}
