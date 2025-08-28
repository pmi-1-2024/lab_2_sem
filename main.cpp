#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <string>
#include <iomanip>
#include <algorithm>
#include <windows.h>

using namespace std;

struct Material {
    string date;
    string name;
    double volume;
    double cost;
};

struct Team {
    int teamNumber;
    string supervisor;
    list<Material> materials;
    double totalCost = 0.0;
};

list<Team>::iterator findTeam(list<Team>& teams, int teamNumber, const string& supervisor) {
    for (auto it = teams.begin(); it != teams.end(); ++it) {
        if (it->teamNumber == teamNumber && it->supervisor == supervisor)
            return it;
    }
    return teams.end();
}

int main() {
    SetConsoleOutputCP(1251);
    ifstream inFile("input.txt");
    ofstream outFile("output.txt");
    ofstream totalFile("totals.txt");

    if (!inFile.is_open()) {
        cerr << "Не вдалося відкрити файл input.txt\n";
        return 1;
    }

    list<Team> teams;

    int teamNumber;
    string supervisor, date, name;
    double volume, cost;

    while (inFile >> teamNumber >> supervisor >> date >> name >> volume >> cost) {
        Material mat = { date, name, volume, cost };

        auto it = findTeam(teams, teamNumber, supervisor);
        if (it == teams.end()) {
            Team team;
            team.teamNumber = teamNumber;
            team.supervisor = supervisor;
            team.materials.push_back(mat);
            team.totalCost += cost;
            teams.push_back(team);
        }
        else {
            it->materials.push_back(mat);
            it->totalCost += cost;
        }
    }

    teams.sort([](const Team& a, const Team& b) {
        return a.supervisor < b.supervisor;
        });

    for (const auto& team : teams) {
        cout << "Бригада #" << team.teamNumber << " (" << team.supervisor << ")\n";
        outFile << "Бригада #" << team.teamNumber << " (" << team.supervisor << ")\n";
        for (const auto& mat : team.materials) {
            cout << "  " << mat.date << " " << mat.name << " " << mat.volume << " " << mat.cost << "\n";
            outFile << "  " << mat.date << " " << mat.name << " " << mat.volume << " " << mat.cost << "\n";
        }
        cout << "Загальна сума: " << team.totalCost << "\n\n";
        outFile << "Загальна сума: " << team.totalCost << "\n\n";

        totalFile << "Бригада #" << team.teamNumber << " (" << team.supervisor << "): "
            << fixed << setprecision(2) << team.totalCost << " грн\n";
    }

    inFile.close();
    outFile.close();
    totalFile.close();

    return 0;
}
