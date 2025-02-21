#include "Zalikovka.h"

Zalikovka::Zalikovka():id("none_id"), subjects(nullptr), size(0) {}

Zalikovka::Zalikovka(string i, int size, Subject* s) :id(i), size(size) {
  //  this->id = id;
    this->subjects = new Subject[size];
      
    for (int i = 0; i < size; ++i) {
        this->subjects[i]=s[i];
         }
  }


string Zalikovka::getId() const { 
    return id;
}

void Zalikovka::display() const {
    cout << "Zalikovka ID: " << id << ", size: "<<size<<endl;
    for (int i = 0; i < size; i++) {
        subjects[i].display();
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
