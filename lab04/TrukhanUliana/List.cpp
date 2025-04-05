#include "List.h"

List::List(const List& other) : head(nullptr) {
	if (!other.head) return;

	head = new Link(*other.head);
	Link* currentOther = other.head->next;
	Link* lastNew = head;

	while (currentOther) {
		lastNew->next = new Link(*currentOther);
		lastNew = lastNew->next;
		currentOther = currentOther->next;
	}
}

List& List::operator=(const List& other) {
	if (this != &other) {
		List temp(other);
		swap(head, temp.head);
	}
	return *this;
}

List::~List() {
	while (!empty()) {
		Link* removedNode = remove();
		delete removedNode;
	}
}

void List::push(Link* node) {
	if (!node) return;

	if (!head) head = node;
	else { 
		node->next = head;
		head = node; 
	}
}

Link* List::remove(Link* node) {
	if (!head) return nullptr;

	if (!node) node = head;

	Link* temp = head;
	Link* prev = nullptr;

	if (temp == node) {
		head = head->next;
		node->next = nullptr;
		return node;
	}

	while (temp && temp != node) {
		prev = temp;
		temp = temp->next;
	}

	if (temp == node) {
		prev->next = node->next;
		node->next = nullptr;
		return node;
	}

	return nullptr;
}
