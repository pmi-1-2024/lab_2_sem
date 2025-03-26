#pragma once
#include "List.h"
class Phone_Manager
{
private:
	Phone_list list;
public:
	Phone_Manager();
	~Phone_Manager();
	void add(Phone phone);
	void remove(Phone phone);
	void show();
	Phone* find(string name);
	void changePrice(string name, double price);

};

