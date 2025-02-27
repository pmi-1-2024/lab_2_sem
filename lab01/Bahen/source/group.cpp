#include "group.h" 
#include "student.h"
void Group::add(Student st) {
	
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