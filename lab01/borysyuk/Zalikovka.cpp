#include "Zalikovka.h"

Zalikovka::Zalikovka():id("none_id"), subjects(nullptr), size(0) {}

Zalikovka::Zalikovka(string i, int size, Subject* s) :id(i), size(size) {
  //  this->id = id;
    this->subjects = new Subject[size];
      
    for (int i = 0; i < size; ++i) {
        this->subjects[i]=s[i];
         }
  }
Zalikovka::Zalikovka(const Zalikovka& other) : id(other.id), size(other.size) {
    subjects = new Subject[size];
    for (int i = 0; i < size; i++) {
        subjects[i] = other.subjects[i];
    }
}


Zalikovka& Zalikovka::operator=(const Zalikovka& other) {
    if (this == &other) return *this; 

    delete[] subjects; 

    id = other.id;
    size = other.size;
    subjects = new Subject[size];
    for (int i = 0; i < size; i++) {
        subjects[i] = other.subjects[i];
    }

    return *this;
}


Subject& Zalikovka::operator[](int index) {
    if (index < 0 || index >= size) {
        throw out_of_range("Index out of range");
    }
    return subjects[index];
}

const Subject& Zalikovka::operator[](int index) const {
    if (index < 0 || index >= size) {
        throw out_of_range("Index out of range");
    }
    return subjects[index];
}


Zalikovka::~Zalikovka() {
    delete[] subjects;
}

string Zalikovka::getId() const { 
    return id;
}

void Zalikovka::display(ostream& os) const {
    cout << "Zalikovka ID: " << id << ", size: "<<size<<endl;
    for (int i = 0; i < size; i++) {
        subjects[i].display(os);
    }
}
void Zalikovka::read(istream& is)
{
    if (this->subjects != nullptr) {
        delete[] this->subjects;
    }

    is >> this->id >> this->size;
    this->subjects = new Subject[this->size];

    for (int i = 0; i < this->size; ++i) {
        is >> this->subjects[i];
    }

}

   istream& operator>>(istream& is, Zalikovka& z)
{
    z.read(is);
    return is;
}

   ostream& operator<<(ostream& os, const Zalikovka& z)
   {
       z.display(os);
       return os;
   }
