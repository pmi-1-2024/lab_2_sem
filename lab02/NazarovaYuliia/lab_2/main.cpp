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
        string name;
        int birthYear;
        fin >> name >> birthYear;
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
            string color, breed;
            fin >> color >> breed;
            animals[count++] = new Horse(name, birthYear, color, breed);
        }
        else if (type == "Donkey") {
            string donkeyType;
            double height;
            fin >> donkeyType >> height;
            animals[count++] = new Donkey(name, birthYear, donkeyType, height);
        }
        else if (type == "Mule") {
            string color, breed, donkeyType, nickname;
            double height;
            fin >> color >> breed >> donkeyType >> height >> nickname;
            animals[count++] = new Mule(name, birthYear, color, breed, donkeyType, height, nickname);
        }
    }

    // Сортування за роком народження (бульбашкове сортування)
    for (int i = 0; i < count - 1; ++i) {
        for (int j = i + 1; j < count; ++j) {
            if (animals[i]->getBirthYear() > animals[j]->getBirthYear()) {
                Animal* temp = animals[i];
                animals[i] = animals[j];
                animals[j] = temp;
            }
        }
    }

    for (int i = 0; i < count; ++i) {
        animals[i]->print(fout1);
        fout1 << endl;
    }

    int whiteHorses = 0, shortDonkeys = 0;
    for (int i = 0; i < count; ++i) {
        Horse* h = dynamic_cast<Horse*>(animals[i]);
        if (h && h->getColor() == "white") {
            h->print(fout2);
            fout2 << endl;
            whiteHorses++;
        }
        Donkey* d = dynamic_cast<Donkey*>(animals[i]);
        if (d && d->getHeight() <= 1.5) {
            d->print(fout2);
            fout2 << endl;
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