#include "List.h"

ostream& operator<<(ostream& os, const Student& student) {
	os << "Name: " << student.name
		<< ", Surname: " << student.surname
		<< ", Average grades: " << student.aver;
	return os;
}

istream& operator>>(istream& is, Student& student) {
	cout << "Enter student's name: ";
	is >> student.name;
	cout << "Enter student's surname: ";
	is >> student.surname;
	cout << "Enter student's average grades: ";
	is >> student.aver;
	return is;
}

List::List(const List& other) : head(nullptr) {}

List& List::operator=(const List&) {
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

	// ����������, �� ����� � �������
	if (temp == node) {
		head = head->next;
		node->next = nullptr;
		return node;
	}

	// ������ ����� � ������
	while (temp && temp != node) {
		prev = temp;
		temp = temp->next;
	}

	// ���� ������� �����, ��������� ����
	if (temp == node) {
		prev->next = node->next;
		node->next = nullptr;
		return node;
	}

	return nullptr;
}
