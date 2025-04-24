#include "List.h"

List::List(const List& other) : head(nullptr) {
	if (!other.head) return; 

	head = new Link(*other.head);
	Link* currentNew = head;
	Link* currentOther = other.head->next;

	while (currentOther) {
		currentNew->next = new Link(*currentOther);
		currentNew = currentNew->next;
		currentOther = currentOther->next;
	}
}

List& List::operator=(const List& other)
{
	if (this == &other) return *this; 

	while (!empty()) {
		delete remove(head);
	}
	if (!other.head) {
		head = nullptr;
		return *this;
	}

	head = new Link(*other.head);
	Link* currentNew = head;
	Link* currentOther = other.head->next;

	while (currentOther) {
		currentNew->next = new Link(*currentOther);
		currentNew = currentNew->next;
		currentOther = currentOther->next;
	}

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
