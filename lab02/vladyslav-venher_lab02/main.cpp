#include "Horse.h"
#include "Donkey.h"
#include "Mule.h"

#include <fstream>
using namespace std;

const int MAX_ANIMALS = 100; 

istream& operator>>(istream& is, Animal*& animal) {
    int type;
    is >> type;
    if (type == 1) {
        string name, color, breed;
        int birthYear;
        is >> name >> birthYear >> color >> breed;
        animal = new Horse(name, birthYear, color, breed);
    }
    else if (type == 2) {
        string name, type;
        int birthYear;
        double height;
        is >> name >> birthYear >> type >> height;
        animal = new Donkey(name, birthYear, type, height);
    }
    else if (type == 3) {
        string name, color, breed, type, nickname;
        int birthYear;
        double height;
        is >> name >> birthYear >> color >> breed >> type >> height >> nickname;
        animal = new Mule(name, birthYear, color, breed, type, height, nickname);
    }
    return is;
}

int main() {
    ifstream inputFile("animals.txt");
    ofstream file1("File1.txt"), file2("File2.txt");

    if (!inputFile) {
        cerr << "Error opening input file.\n";
        return 1;
    }

    Animal* animals[MAX_ANIMALS];
    int count = 0;

    while (!inputFile.eof() && count < MAX_ANIMALS) {
        Animal* animal = nullptr;
        inputFile >> animal;
        if (animal) animals[count++] = animal;
    }

    for (int i = 0; i < count - 1; ++i) {
        for (int j = 0; j < count - i - 1; ++j) {
            if (animals[j]->getBirthYear() > animals[j + 1]->getBirthYear()) {
                swap(animals[j], animals[j + 1]);
            }
        }
    }

    for (int i = 0; i < count; ++i) {
        animals[i]->display(file1);
    }

    int whiteHorses = 0, shortDonkeys = 0;
    for (int i = 0; i < count; ++i) {

        if (dynamic_cast<Mule*>(animals[i]) != nullptr) {
            continue; 
        }

        if (animals[i]->isWhiteHorse()) {
            whiteHorses++;
            animals[i]->display(file2);
        }

        if (animals[i]->isShortDonkey()) {
            shortDonkeys++;
            animals[i]->display(file2);
        }
    }

    file2 << "White Horses: " << whiteHorses << '\n';
    file2 << "Short Donkeys: " << shortDonkeys << '\n';


    for (int i = 0; i < count; ++i) delete animals[i];
}
