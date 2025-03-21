#include <iostream>
#include <fstream>
#include "Phone.h"
#include "MobilePhone.h"
#include "RadioPhone.h"
#include "HybridPhone.h"

using namespace std;

int main()
{
	ifstream file1("file1.txt");
	ifstream file2("file2.txt");

	int count1 = 0;
	int count2 = 0;

	file1 >> count1;
	file2 >> count2;

	Phone** phones = new Phone * [count1 + count2];

	for (int i = 0; i < count1; i++)
	{
		string type;
		file1 >> type;
		if (type == "Mobile")
		{
			phones[i] = new MobilePhone();
			file1 >> *phones[i];
		}
		else if (type == "Radio")
		{
			phones[i] = new RadioPhone();
			file1 >> *phones[i];
		}
		else if (type == "Hybrid")
		{
			phones[i] = new HybridPhone();
			file1 >> *phones[i];
		}
	}


	for (int i = count1; i < count1 + count2; i++)
	{
		string type;
		file2 >> type;
		if (type == "Mobile")
		{
			phones[i] = new MobilePhone();
			file2 >> *phones[i];
		}
		else if (type == "Radio")
		{
			phones[i] = new RadioPhone();
			file2 >> *phones[i];
		}
		else if (type == "Hybrid")
		{
			phones[i] = new HybridPhone();
			file2 >> *phones[i];
		}
	}

	for (int i = 0; i < count1 + count2 - 1; i++) {
		for (int j = 0; j < count1 + count2 - i - 1; j++) {
			if (*phones[j] > *phones[j + 1]) {
				Phone* temp = phones[j];
				phones[j] = phones[j + 1];
				phones[j + 1] = temp;
			}
		}
	}
	ofstream file3("file3.txt");
	for (int i = 0; i < count1 + count2; i++)
	{
		file3 << *phones[i] << endl;
	}

	int sum = 0;
	for (int i = 0; i < count1 + count2; i++)
	{
		sum += phones[i]->getPrice();
	}
	file3 << sum << endl;

	for (int i = 0; i < count1 + count2; i++)
	{
		if (dynamic_cast<RadioPhone*>(phones[i]))
		{
			if (dynamic_cast<RadioPhone*>(phones[i])->getAnsweringMachine())
			{
				file3 << *phones[i] << endl;
			}
		}
	}
	file1.close();
	file2.close();
	file3.close();
	for (int i = 0; i < count1 + count2; i++)
	{
		delete phones[i];
	}

	return 0;
}