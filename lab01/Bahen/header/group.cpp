#include "group.h" 
#include "student.h"
void Group::add(Student st) {
	
	list[size] = st;
	size++;
}

int Group::get_size() {
	return size;
};

ostream& operator << (ostream& out, const Group& g)
{
	for(int i =0;i < g.size; i++)
	out << g.list[i];
	return out;
}

Student* Group::get_list() {
	return list;
}