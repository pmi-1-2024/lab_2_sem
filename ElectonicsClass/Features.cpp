#include "Features.h"

void Readfile(ifstream& file, Electroprilad** prilads,int &count)
{
	if(!file.is_open()) {
		cout << "\nFile is not open!";
		return;
	}
	count = 0;
	string name;
	while (file >> name) {
		string firm;
		int price;
		if (name == "Vacuumcleaner") {
			int power;
			string color;
			file >> firm >> price >> power >> color;
			prilads[count++] = new Vacuumcleaner(name, firm, price, power, color);
		}
		else if(name=="Washingmachine")
		{
			int countop, capacity;
			file >> firm >> price >> countop >> capacity;
			prilads[count++] = new Washmash(name, firm, price, countop, capacity);
		}
		else if (name == "Combine") {
			int cpower, countf;
			file >> firm >> price >> cpower >> countf;
			prilads[count++] = new Combine(name, firm, price, cpower, countf);
		}
	}	
}

void NameSort(Electroprilad** prilads, int count)
{
	for (int i = 0; i < count - 1; i++) {
		for (int j = 0; j < count - i - 1; j++) {
			if (prilads[j]->GetName() > prilads[j + 1]->GetName()) {
				Electroprilad* temp = prilads[j];
				prilads[j] = prilads[j + 1];
				prilads[j + 1] = temp;
			}
		}
	}
}

void WriteSortToFile(ofstream& file, Electroprilad** prilads, int count)
{
	if (!file.is_open()) {
		cout << "\nFile is not open!";
		return;
	}
	NameSort(prilads, count);
	int vc = 0;
	int wm = 0;
	int cm = 0;
	for (int i = 0; i < count; i++) {
		file << *prilads[i] << "\n";
		if (prilads[i]->GetName() == "Vacuumcleaner") {
			vc++;
		}
		else if (prilads[i]->GetName() == "Washingmachine") {
			wm++;
		}
		else if (prilads[i]->GetName() == "Combine") {
			cm++;
		}
	}
	file << "\nCount of prilads: " << count;
	file << "\nCount of Vacuumcleaners: " << vc;
	file << "\nCount of Washingmachines: " << wm;
	file << "\nCount of Combines: " << cm;
	cout << "\nAfter sorting: ";
	for (int i = 0; i < count; i++) {
		cout << prilads[i]->GetName() << "\n";
	}
	cout << "\nCount of prilads: " << count;
	cout << "\nCount of Vacuumcleaners: " << vc;
	cout << "\nCount of Washingmachines: " << wm;
	cout << "\nCount of Combines: " << cm;
}

void WriteFirmToFile(ofstream& file, Electroprilad** prilads, int count,const string& firm)
{
	if (!file.is_open()) {
		cout << "\nFile is not open!";
		return;
	}
	file << "\nFirm: " << firm;
	int Finalprice = 0;
	for(int i=0;i<count;i++){
		if (prilads[i]->GetFirm() == firm) {
			file <<"\nDevice from this company: "<< prilads[i]->GetName();
			Finalprice += prilads[i]->GetPrice();
		}
	}
	file << "\nFinal price: " << Finalprice;
	cout << "\nFirm: " << firm;
	cout << "\nFinal price: " << Finalprice;
}

