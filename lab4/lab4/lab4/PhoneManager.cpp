#include "PhoneManager.h"

void PhoneManager::add(Phone* p) {
	list.push(p);
}

void PhoneManager::removeByName(string name) {
	Phone_Link* found = list.findByName(name);
	if (found) {
		Link* del = list.remove(found);
		delete ((Phone_Link*)del)->data;
		delete del;
	}
}

void PhoneManager::search(string name, ostream& out) {
	Phone_Link* f = list.findByName(name);
	if (f) out << *(f->data);
	else out << "Not found\n";
}

void PhoneManager::printAll(ostream& out) {
	list.printAll(out);
}
