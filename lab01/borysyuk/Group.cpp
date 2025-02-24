#include"Group.h"
Group::Group() :namegroup("none_namegroup"),size(0), groupa(nullptr) {}
Group::Group(string nameg, int size, Student* s) :namegroup(nameg), size(size) {
	this->groupa = new Student[size];

	for (int i = 0; i < size; ++i) {
		this->groupa[i] = s[i];

	}
}

void Group::display() const
{
	cout << "Group name: " << namegroup << ", size: " << size << endl;
	for (int i = 0; i < size; ++i) {
		groupa[i].display();
	}
}

void Group::read(istream& is)
{
	if (this->groupa != nullptr) {
		delete[] this->groupa;
	}
	is >> this->namegroup >> this->size;
	this->groupa = new Student[this->size];
	for (int i = 0; i < this->size; ++i) {
		is >> this->groupa[i];
	}
}

string Group::getnamegroup() const
{
	return namegroup;
}

istream& operator>>(istream& is, Group& g)
{
	g.read(is);
	return is; 
}
