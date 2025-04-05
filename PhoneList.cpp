#include "PhoneList.h"

void Phone_List::push(Phone* p) {
	Phone_Link* temp = new Phone_Link(p);
	List::push(temp);
}

Phone_Link* Phone_List::findByName(string name) {
	Phone_Link* temp = (Phone_Link*)head;
	while (temp) {
		if (temp->data->getName() == name) return temp;
		temp = (Phone_Link*)temp->next;
	}
	return 0;
}

void Phone_List::printAll(ostream& out) {
	Phone_Link* temp = (Phone_Link*)head;
	while (temp) {
		out << *(temp->data);
		temp = (Phone_Link*)temp->next;
	}
}
