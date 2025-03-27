#include "Address_List.h"

void Address_list::push(Address a)
{
	Address_link* temp = new Address_link(a);
	List::push(temp);
}


Address_link* Address_list::top() const
{
	return (Address_link*)head;;
}


Address_link* Address_list::find(const Address& a)
{
	Address_link* temp = (Address_link*)head;
	while (temp) {
		if (temp->data.getIndex() == a.getIndex() && temp->data.getCity() == a.getCity() && temp->data.getStreet() == a.getStreet())
			return temp;
		temp = (Address_link*)(temp->next);
	}
	return 0;
}


void Address_list::insert(Address a, Address_link* after)
{
	if (!after) return;
	Address_link* newnode = new Address_link(a);
	newnode->next = after->next;
	after->next = newnode;
}
