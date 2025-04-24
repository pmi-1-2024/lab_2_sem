#include "List.h"

List::List() { head = 0; }

List::~List() {

	while (head) {
		Link* temp = head;
		head = head->next;
		delete temp;
	}
}


void List::push(Link* node) {

	if (!head) head = node;
	else {
		node->next = head;
		head = node;
	}
}

Link* List::remove(Link* node) {


	if (!node) node = head;

	Link* temp = head;

	if (temp == node) {

		head = head->next;

		node->next = 0;

		return node;
	}

	Link* prev = temp;

	temp = temp->next;

	while (temp) {


		if (temp == node) {

			prev->next = temp->next;
			node->next = 0;
			return node;
		}


		prev = temp;

		temp = temp->next;
	}

	return 0;
}

bool List::empty() {
	return !head;
}
