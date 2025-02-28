#include "group.h" 
#include "student.h"
void Group::add(Student st) {
	if (index == capacity) {
		Student* sub_list = new Student[capacity * 2];
		for (int i = 0; i < capacity; i++) {
			sub_list[i] = list[i];
		}
		delete[] list;
		list = sub_list;
		capacity *= 2;
	}
	list[index] = st;
	index++;
}

int Group::get_size() {
	return index;
};

ostream& operator << (ostream& out, const Group& g)
{
	for(int i =0;i < g.index; i++)
	out << g.list[i];
	return out;
}

Student* Group::get_list() {
	return list;
}

Student& Group::operator[](int id) {
	if (id >= index) {
		cout << "Array index out of bound, exiting";
		exit(0);
	}
	return list[id];
}