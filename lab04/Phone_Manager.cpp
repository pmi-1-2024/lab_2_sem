#include "Phone_Manager.h"

Phone_Manager::Phone_Manager()
{
}

Phone_Manager::~Phone_Manager()
{
	
}

void Phone_Manager::add(Phone phone)
{
	list.push(phone);
}

void Phone_Manager::remove(Phone phone)
{
	list.remove(list.find(phone));
}

void Phone_Manager::show()
{
	Phone_link* temp = list.find(list.top());
	while (temp)
	{
		cout << temp->data << endl;
		temp = (Phone_link*)(temp->next);
	}
}

Phone* Phone_Manager::find(string name)
{
	Phone_link* temp = list.find(list.top());
	while (temp)
	{
		if (temp->data.getName() == name)
			return &temp->data;
		temp = (Phone_link*)(temp->next);
	}
}

void Phone_Manager::changePrice(string name, double price)
{
	Phone* temp = find(name);
	temp->setPrice(price);
}
