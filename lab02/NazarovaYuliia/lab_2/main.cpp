#include "Horse.h"
#include "Donkey.h"
#include "Mule.h"

int main() {
    ifstream fin("input.txt");
    ofstream fout1("output1.txt");
    ofstream fout2("output2.txt");

    int capacity = 10;
    int count = 0;
    Animal** animals = new Animal * [capacity];

    string type;
    while (fin >> type) {        
        if (count == capacity) {
            capacity *= 2;
            Animal** temp = new Animal * [capacity];
            for (int i = 0; i < count; ++i) {
                temp[i] = animals[i];
            }
            delete[] animals;
            animals = temp;
        }
        if (type == "Horse") {
            Horse* h = new Horse();
            fin >> *h;
            animals[count++] = h;
        }
        else if (type == "Donkey") {
            Donkey* d = new Donkey();
            fin >> *d;
            animals[count++] = d;
        }
        else if (type == "Mule") {
            Mule* m = new Mule();
            fin >> *m;
            animals[count++] = m;
        }
    }

    for (int i = 0; i < count - 1; ++i) {
        for (int j = i + 1; j < count; ++j) {
            if (*animals[j] < *animals[i]) {
                swap(animals[i], animals[j]);
            }
        }
    }

    for (int i = 0; i < count; ++i) {
        fout1 << *animals[i] << endl;
    }

    int whiteHorses = 0, shortDonkeys = 0;
    for (int i = 0; i < count; ++i) {
        Horse* h = dynamic_cast<Horse*>(animals[i]);
        if ( h && h->getColor() == "white") {
            fout2 << *h << endl;
            whiteHorses++;
        }
        Donkey* d = dynamic_cast<Donkey*>(animals[i]);
        if ( d && d->getHeight() <= 1.5) {
            fout2 << *d << endl;
            shortDonkeys++;
        }
    }
    fout2 << "Number of white horses: " << whiteHorses << endl;
    fout2 << "Number of donkeys <=1.5m: " << shortDonkeys << endl;

    for (int i = 0; i < count; ++i) delete animals[i];
    delete[] animals;

    fin.close();
    fout1.close();
    fout2.close();
    return 0;
}