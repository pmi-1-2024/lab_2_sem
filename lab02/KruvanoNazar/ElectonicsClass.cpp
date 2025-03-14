#include <iostream>
#include "Features.h"
#include <fstream>
int main()
{
	ifstream file("prilads.txt");
	int count = 0;
	Electroprilad* prilads[7];
	Readfile(file, prilads,count);
	
	file.close();
	ofstream fileone("sortnamefile.txt");
	WriteSortToFile(fileone, prilads, count);
	fileone.close();

	ofstream filetwo("firmsort.txt");
	string firm;
	cout << "\nChoice firm: ";
	cout << "\n1. Samsung" << "\n2. LG" << "\n3. Bosh" << "\n4. Philips";
	cout << "\nEnter choice: ";
	cin >> firm;
	WriteFirmToFile(filetwo, prilads, count, firm);
	filetwo.close();

	for (int i = 0; i < count; i++) {
		delete prilads[i];
	}

}
