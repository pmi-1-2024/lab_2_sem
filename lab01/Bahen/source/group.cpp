#include "group.h" 

Group::Group() {
	name = "";
	index = 0;
	capacity = 8;
	list = new Student[capacity];
};

Group::Group(const Group& other_g) {
	capacity = other_g.capacity;
	index = other_g.index;
	list = new Student[capacity];
	for (int i = 0; i < index; i++) list[i] = other_g.list[i];
}

Group::~Group() {
	delete[] list;
}

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

Group& Group::operator=(const Group& other_g) {
	if (this == &other_g) {
		return *this;
	}

	delete[] list;
	capacity = other_g.capacity;
	index = other_g.index;
	list = new Student[capacity];
	for (int i = 0; i < index; i++) list[i] = other_g.list[i];

	return *this;
}