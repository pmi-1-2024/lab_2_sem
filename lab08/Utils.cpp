#include "Utils.h"
#include <fstream>
#include <iostream>
using namespace std;
bool compareTeams(const Team& a, const Team& b) {
    return a.getNumber() < b.getNumber();
}
list<Team> readTeams() {
    ifstream file("data.txt");
    if (!file.is_open()) {
        throw FileException("Failed to open data.txt");
    }

    list<Team> teams;
    int number;
    string master;

    while (file >> number >> master) {
        Material m;
        if (!(file >> m)) {
            throw DataException("Invalid material data in data.txt");
        }
        bool found = false;
        for (Team& team : teams) {
            if (team.getNumber() == number) {
                team.addMaterial(m);
                found = true;
                break;
            }
        }

        if (!found) {
            Team newTeam(number, master);
            newTeam.addMaterial(m);
            teams.push_back(newTeam);
        }
    }

    teams.sort(compareTeams);

    if (file.bad()) {
        throw FileException("Error reading data.txt");
    }

    file.close();
    return teams;
}
void saveTeams(const list<Team>& teams) {
    ofstream file("teams.txt");
    if (!file.is_open()) {
        throw FileException("Failed to create teams.txt");
    }

    for (const Team& team : teams) {
        file << team;
    }

    if (file.fail()) {
        throw FileException("Error writing to teams.txt");
    }

    file.close();
}

list<Material> summarizeMaterials(const list<Team>& teams) {
    list<Material> summary;

    for (const Team& team : teams) {
        for (const Material& material : team.getMaterials()) {
            bool found = false;
            for (Material& sumMat : summary) {
                if (sumMat.sameName(material.getName())) {
                    sumMat.accumulate(material.getVolume(), material.getCost());
                    found = true;
                    break;
                }
            }

            if (!found) {
                summary.push_back(Material("", material.getName(),
                    material.getVolume(), material.getCost()));
            }
        }
    }

    return summary;
}
void saveMaterials(const list<Material>& materials) {
	ofstream file("materials.txt");
	if (!file.is_open()) {
		throw FileException("Failed to create materials.txt");
	}
    file << "Materials summary:\n";
    for (const Material& m : materials) {
        file << m.getName() << " Total volume: " << m.getVolume()
            << ", Total cost: " << m.getCost() << "\n";
    }

    if (file.fail()) {
        throw FileException("Error writing to materials.txt");
    }

    file.close();
}
void printTeams(const list<Team>& teams) {
	cout << "Teams:\n";
	for (const Team& team : teams) {
		cout << team;
	}
}
void printMaterials(const list<Material>& materials) {
	cout << "Materials summary:\n";
	for (const Material& m : materials) {
		cout << m.getName() << " Total volume: " << m.getVolume()
			<< ", Total cost: " << m.getCost() << "\n";
	}
}