#include "funcs.h"
#include <fstream>
#include <algorithm>

bool compBrigadier(Brigade a, Brigade b) {
    return a.getBrigadier() < b.getBrigadier();
}

void parseLine(string line, int& id, string& brigadier, Expense& exp) {
    size_t pos = line.find('\t');
    id = stoi(line.substr(0, pos));
    line = line.substr(pos + 1);

    pos = line.find('\t');
    brigadier = line.substr(0, pos);
    line = line.substr(pos + 1);

    pos = line.find('\t');
    exp.setDate(line.substr(0, pos));
    line = line.substr(pos + 1);

    pos = line.find('\t');
    exp.setMaterial(line.substr(0, pos));
    line = line.substr(pos + 1);

    pos = line.find('\t');
    exp.setVolume(stod(line.substr(0, pos)));
    exp.setCost(stod(line.substr(pos + 1)));
}

void fileRead(string filename, deque<Brigade>& brigades) {
    ifstream file(filename);
    if (!file.is_open()) return;

    string line;
    while (getline(file, line)) {
        int id;
        string brigadier;
        Expense exp;

        parseLine(line, id, brigadier, exp);

        bool found = false;
        for (int i = 0; i < brigades.size(); i++) {
            if (brigades[i].getId() == id) {
                brigades[i].addExp(exp);
                found = true;
                break;
            }
        }

        if (!found) {
            Brigade newBrigade(id, brigadier);
            newBrigade.addExp(exp);
            brigades.push_back(newBrigade);
        }
    }

    file.close();
}

void fileWrite(string filename, deque<Brigade> brigades) {
    ofstream file(filename);
    if (!file.is_open()) return;

    for (int i = 0; i < brigades.size(); i++) {
        file << "Brigade ID: " << brigades[i].getId() << ", : " << brigades[i].getBrigadier() << "\n";
        deque<Expense> exps = brigades[i].getExp();
        for (int j = 0; j < exps.size(); j++) {
            file << "  Date: " << exps[j].getDate()
                << ", Material: " << exps[j].getMaterial()
                << ", Volume: " << exps[j].getVolume()
                << ", Cost: " << exps[j].getCost() << "\n";
        }
        file << "Total Cost: " << brigades[i].getTotal() << "\n\n";
    }
    file.close();
}