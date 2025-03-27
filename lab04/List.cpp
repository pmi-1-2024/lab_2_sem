#include "List.h"
void List::push(Link* node) {
	if (!head) head = node;
	else { node->next = head; head = node; }
}

List::~List()
{
}

Link* List::remove(Link* node)
{
	if (!node) {
		return nullptr;
	}
	if (node == head) {
		head = head->next;
		node->next = nullptr;
		return node;
	}
	Link* temp = head;
	while (temp && temp->next) {
		if (temp->next == node) {
			temp->next = node->next;
			node->next = nullptr;
			return node;
		}
		temp = temp->next;
	}
	return nullptr;
}

void Phone_list::push(Phone a) {
	Phone_link* temp = new Phone_link(a);
	List::push(temp);
}
Phone_link* Phone_list::find(Phone a)
{
	Phone_link* temp = (Phone_link*)head;
	while (temp)
	{
		if (temp->data == a)
			return temp;
		temp = (Phone_link*)(temp->next);
	}
	return 0;
}

void Phone_list::insert(Phone a, Phone_link* after)
{
	if (!after)
	{
		push(a);
		return;
	}
	Phone_link* temp = new Phone_link(a);
	temp->next = after->next;
	after->next = temp;
}

