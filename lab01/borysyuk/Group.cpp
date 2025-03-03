#include"Group.h"
Group::Group() :namegroup("none_namegroup"),size(0), groupa(nullptr) {}
Group::Group(string nameg, int size, Student* s) :namegroup(nameg), size(size) {
	this->groupa = new Student[size];

	for (int i = 0; i < size; ++i) {
		this->groupa[i] = s[i];

	}
}

void Group::display(ostream& os) const
{
	cout << "Group name: " << namegroup << ", size: " << size << endl;
	for (int i = 0; i < size; ++i) {
		groupa[i].display(os);
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

Group::Group(const Group& other) : namegroup(other.namegroup), size(other.size) {
    groupa = new Student[size];
    for (int i = 0; i < size; i++) {
        groupa[i] = other.groupa[i];
    }
}


Group& Group::operator=(const Group& other) {
    if (this == &other) return *this;

    delete[] groupa; 

    namegroup = other.namegroup;
    size = other.size;
    groupa = new Student[size];
    for (int i = 0; i < size; i++) {
        groupa[i] = other.groupa[i];
    }

    return *this;
}


Student& Group::operator[](int index) {
    if (index < 0 || index >= size) {
        throw out_of_range("Index out of range");
    }
    return groupa[index];
}

const Student& Group::operator[](int index) const {
    if (index < 0 || index >= size) {
        throw out_of_range("Index out of range");
    }
    return groupa[index];
}


Group::~Group() {
    delete[] groupa;
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

ostream& operator<<(ostream& os, const Group& g)
{
	g.display(os);
	return os;
}
