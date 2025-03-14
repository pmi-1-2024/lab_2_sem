#include "Features.h"

void Readfile(ifstream& file, Electroprilad** prilads,int &count)
{
	if(!file.is_open()) {
		cout << "\nFile is not open!";
		return;
	}
	count = 0;
	int type ;
	Vacuumcleaner v1;
	Washmash w1;
	Combine c1;
	for (int i = 0; i < 7; i++) {
		file >> type;
		switch (type) {
		case 1:
			file >> v1;
			prilads[count++] = new Vacuumcleaner(v1);
			break;
		case 2:
			file >> w1;
			prilads[count++] = new Washmash(w1);
			break;
		case 3:
			file >> c1;
			prilads[count++] = new Combine(c1);
			break;
		}
	}
}

void NameSort(Electroprilad** prilads, int count)
{
	for (int i = 0; i < count - 1; i++) {
		for (int j = 0; j < count - i - 1; j++) {
			if (*prilads[j + 1] < *prilads[j]) {
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
		cout <<"\n " << prilads[i]->GetName() << "\n";
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

