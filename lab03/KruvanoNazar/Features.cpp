#include "Features.h"

void Readfile(ifstream& file, Electroprilad** prilads, int& count, SuperRobot **robots, int& rcount)
{
	if (!file.is_open()) {
		cout << "\nFile is not open!";
		return;
	}
	count = 0;
	rcount = 0;
	int type;
	for (int i = 0; i < 10; i++) {
		Electroprilad* e1 = nullptr;
		file >> type;
		switch (type) {
		case 1:
			e1 = new Vacuumcleaner();
			break;
		case 2:
			e1 = new Washmash();
			break;
		case 3:
			e1 = new Combine();
			break;
		case 4:
			e1 = new SuperRobot();
			break;
		}
		file >> *e1;
		type == 4 ? robots[rcount++] = dynamic_cast<SuperRobot*>(e1) : prilads[count++] = e1;
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

void SearchMenu()
{
	cout << "\nChoose a number of criteria to find a device: ";
	cout << "\n1. Name" << "\n2. Firm" << "\n3. Price" << "\n4. Power of vacuumcleaner " << "\n5. Color of vacuumcleaner" << "\n6. Washing machine count of programs" << "\n7. Capacity of washing machine" << "\n8. Power of combine" << "\n9. Combine count of functions";
	cout << "\nEnter choice: ";
}

void SearchByCriteriaAndWriteToFile(ofstream& file, SuperRobot **robots, int rcount, int search)
{
	if (!file.is_open()) {
		cout << "\nFile is not open!";
		return;
	}

	string searchword;
	int searchterm;
	if (search == 1 || search == 2 || search == 5) {
		cout << "\n Enter a search query:";
		cin >> searchword;
	}
	else {
		cout << "\n Enter a search query:";
		cin >> searchterm;
	}
	switch (search) {
	case 1:
		for (int i = 0; i < 3; i++) {
			if (robots[i]->GetName() == searchword) {
				file << *robots[i];
				cout << "\nThe information was written to a file";
				cout << *robots[i];
			}
		}
		break;
	case 2:
		for (int i = 0; i < 3; i++) {
			if (robots[i]->GetFirm() == searchword) {
				file << *robots[i];
				cout << "\nThe information was written to a file";
				cout << *robots[i];
			}
		}
		break;
	case 3:
		for (int i = 0; i < 3; i++) {
			if (robots[i]->GetPrice() == searchterm) {
				file << *robots[i];
				cout << "\nThe information was written to a file";
				cout << *robots[i];
			}
		}
		break;
	case 4:
		for (int i = 0; i < 3; i++) {
			if (robots[i]->Getpower() == searchterm) {
				file << *robots[i];
				cout << "\nThe information was written to a file";
				cout << *robots[i];
			}
		}
		break;
	case 5:
		for (int i = 0; i < 3; i++) {
			if (robots[i]->GetColor() == searchword) {
				file << *robots[i];
				cout << "\nThe information was written to a file";
				cout << *robots[i];
			}
		}
		break;
	case 6:
		for (int i = 0; i < 3; i++) {
			if (robots[i]->GetCountOfPrograms() == searchterm) {
				file << *robots[i];
				cout << "\nThe information was written to a file";
				cout << *robots[i];
			}
		}
		break;
	case 7:
		for (int i = 0; i < 3; i++) {
			if (robots[i]->GetCapacity() == searchterm) {
				file << *robots[i];
				cout << "\nThe information was written to a file";
				cout << *robots[i];
			}
		}
		break;
	case 8:
		for (int i = 0; i < 3; i++) {
			if (robots[i]->GetCombinePower() == searchterm) {
				file << *robots[i];
				cout << "\nThe information was written to a file";
				cout << *robots[i];
			}
		}
		break;
	case 9:
		for (int i = 0; i < 3; i++) {
			if (robots[i]->GetCountOfFunctions() == searchterm) {
				file << *robots[i];
				cout << "\nThe information was written to a file";
				cout << *robots[i];
			}
		}
		break;
	}

}

