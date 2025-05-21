#include "FileUtils.h"
#include <fstream>
#include <sstream>
#include <stdexcept>

vector<TeamData> readFromFile(const string& filename) {
    ifstream fin(filename);
    if (!fin.is_open()) throw runtime_error("Cannot open file: " + filename);

    vector<TeamData> allData;
    string line;
    while (getline(fin, line)) {
        if (line.empty()) continue;

        TeamData team;
        istringstream iss(line);
        if (!(iss >> team.teamNumber)) throw runtime_error("Invalid team number line: " + line);
        getline(fin, team.foreman);

        string materialLine;
        while (getline(fin, materialLine) && !materialLine.empty()) {
            istringstream matStream(materialLine);
            Material mat;
            if (!(matStream >> mat.date >> mat.name >> mat.volume >> mat.cost))
                throw runtime_error("Invalid material line: " + materialLine);
            team.materials.push_back(mat);
        }

        allData.push_back(team);
    }
    return allData;
}

void mergeTeams(const vector<TeamData>& teams, map<int, TeamData>& merged) {
    for (const auto& team : teams) {
        auto& entry = merged[team.teamNumber];
        if (entry.materials.empty()) {
            entry.teamNumber = team.teamNumber;
            entry.foreman = team.foreman;
        }
        entry.materials.insert(entry.materials.end(), team.materials.begin(), team.materials.end());
    }
}

void saveTeamsToFile(const map<int, TeamData>& merged, const string& filename) {
    ofstream fout(filename);
    if (!fout.is_open()) throw runtime_error("Cannot open output file: " + filename);

    for (const auto& [num, team] : merged) {
        fout << "Team #" << team.teamNumber << " (" << team.foreman << ")\n";
        for (const auto& m : team.materials) {
            fout << "  " << m.date << " - " << m.name << " - " << m.volume << " m3 - $" << m.cost << "\n";
        }
        fout << endl;
    }
}
