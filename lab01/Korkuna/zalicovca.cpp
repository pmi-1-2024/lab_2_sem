#include "zalicovca.h"

Zalicovca::Zalicovca() {
    id = "0";
    size = 0;
    array = 0;
}

Zalicovca::Zalicovca(const Zalicovca& other_z) {
    size = other_z.size;
    array = new Predmet[size];
    for (int i = 0; i < size; i++) array[i] = other_z.array[i];

}


ostream& operator << (ostream& out, const Zalicovca& z)
{
    out << "Id:" << z.id << " Size:" << z.size<<endl;

    for (int i = 0; i < z.size; i++) {
        out << z.array[i];
    }
    return out;
}

istream& operator >> (istream& in, Zalicovca& z)
{
    cout << "Id: ";
    in >> z.id;
    cout << "Size: ";
    in >> z.size;
    
    if (z.array != 0) delete[] z.array;
    z.array = new Predmet[z.size];
    cout << "Predments"<<endl;
    cout << "__________" << endl;
    for (int i = 0; i < z.size; i++) {
        in >> z.array[i];
    }
    return in;
}

Predmet& Zalicovca::operator[](int id) {
    if (id >= size) {
        cout << "Array index out of bound, exiting";
        exit(0);
    }
    return array[id];
}

Zalicovca& Zalicovca::operator=(const Zalicovca& other_z) {
    if (this == &other_z) { 
        return *this;
    }

    delete[] array;
    size = other_z.size;
    array = new Predmet[size];
    for (int i = 0; i < size; i++) array[i] = other_z.array[i];

    return *this;
}
string Zalicovca::get_id() {
    return id;
}

bool Zalicovca::is_subject(string sub) {
    for (int i = 0; i < size; i++) if (sub == array[i].get_name()) return true;
    return false;
}