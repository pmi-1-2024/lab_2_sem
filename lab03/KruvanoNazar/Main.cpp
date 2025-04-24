#include <iostream>
#include "Features.h"
#include <fstream>
#include "SuperRobot.h"
int main()
{
	ifstream file("prilads.txt");
	int count = 0;
	int rcount = 0;
	SuperRobot *robots[3];
	Electroprilad* prilads[7];
	Readfile(file, prilads, count,robots,rcount);
	
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
	ofstream filethree("search.txt");
	int rsearch;
	SearchMenu();
	cin >> rsearch;
	SearchByCriteriaAndWriteToFile(filethree, robots, rcount, rsearch);

	for (int i = 0; i < count; i++) {
		delete prilads[i];
	}

}
