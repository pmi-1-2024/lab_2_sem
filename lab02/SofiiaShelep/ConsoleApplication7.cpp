#include <iostream>
#include <fstream>
#include "Phone.h"
#include "MobilePhone.h"
#include "RadioPhone.h"

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
			string name;
			string brand;
			double price;
			string color;
			int memory;
			file1 >> name >> brand >> price >> color >> memory;
			phones[i] = new MobilePhone(name, brand, price, color, memory);
		}
		else if (type == "Radio")
		{
			string name;
			string brand;
			double price;
			double range;
			bool answeringMachine;
			file1 >> name >> brand >> price >> range >> answeringMachine;
			phones[i] = new RadioPhone(name, brand, price, range, answeringMachine);
		}
	}

	for (int i = count1; i < count1+count2; i++)
	{
		string type;
		file2 >> type;
		if (type == "Mobile")
		{
			string name;
			string brand;
			double price;
			string color;
			int memory;
			file2 >> name >> brand >> price >> color >> memory;
			phones[i] = new MobilePhone(name, brand, price, color, memory);
		}
		else if (type == "Radio")
		{
			string name;
			string brand;
			double price;
			double range;
			bool answeringMachine;
			file2 >> name >> brand >> price >> range >> answeringMachine;
			phones[i] = new RadioPhone(name, brand, price, range, answeringMachine);
		}
	}

	for (int i = 0; i < count1 + count2 - 1; i++) {
		for (int j = 0; j < count1 + count2 - i - 1; j++) {
			if (phones[j]->getPrice() > phones[j + 1]->getPrice()) {
				Phone* temp = phones[j];
				phones[j] = phones[j + 1];
				phones[j + 1] = temp;
			}
		}
	}
	ofstream file3("file3.txt");
	for (int i = 0; i < count1 + count2; i++)
	{
		file3 << phones[i]->getName() << " " << phones[i]->getBrand() << " " << phones[i]->getPrice() <<" ";
		if (dynamic_cast<MobilePhone*>(phones[i]))
		{
			file3  << dynamic_cast<MobilePhone*>(phones[i])->getColor() << " " << dynamic_cast<MobilePhone*>(phones[i])->getMemory() << endl;
		}
		else if (dynamic_cast<RadioPhone*>(phones[i]))
		{
			file3 << dynamic_cast<RadioPhone*>(phones[i])->getRange() << " " << dynamic_cast<RadioPhone*>(phones[i])->getAnsweringMachine() << endl;
		}
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
				file3 << phones[i]->getName() << " " << phones[i]->getBrand() << " " << phones[i]->getPrice() << " " << dynamic_cast<RadioPhone*>(phones[i])->getRange() << " " << dynamic_cast<RadioPhone*>(phones[i])->getAnsweringMachine() << endl;
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
