#include <iostream>
#include <string>
#include "Phone.h"
#include "Link.h"
#include "List.h"
#include "Phone_Manager.h"


using namespace std;

int main()
{
	Phone_Manager manager;
	Phone phone1("Iphone 12", "Apple", 1000);
	Phone phone2("Galaxy S21", "Samsung", 900);
	Phone phone3("Mi 11", "Xiaomi", 800);
	manager.add(phone1);
	manager.add(phone2);
	manager.add(phone3);
	manager.show();
	cout << endl;
	manager.changePrice("Iphone 12", 1200);
	manager.remove(phone2);
	manager.show();
	cout << endl;
	cout << manager.find("Mi 11")->getPrice();

	return 0;

}