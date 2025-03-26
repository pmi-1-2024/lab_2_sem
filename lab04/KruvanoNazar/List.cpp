#include "List.h"

List::List(const List& other) : head(nullptr) {}

List& List::operator=(const List&)
{
	return *this;
}

void List::push(Link* node)
{
	if (!node) return;

	if(!head) head=node;
	else { 
		node->next = head;
		head = node;
	}

}

Link* List::top() const
{
	return head;
}

List::List() : head(0) {}

List::~List()
{
	while (!empty()) {
		Link* temp = remove();
		delete temp;
	}
}

Link* List::remove(Link* node)
{
	if (!node) return nullptr;

	if (node == head) {
		head = head->next;
		node->next = nullptr;
		return node;
	}

	Link* prev = head;
	while (prev->next && prev->next != node) {
		prev = prev->next;
	}

	if (prev->next) {
		prev->next = node->next;
		node->next = nullptr;
		return node;
	}

	return nullptr;
}

bool List::empty() const
{
	return !head;
}
