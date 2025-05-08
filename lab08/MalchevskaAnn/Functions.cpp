#include "Functions.h"
#include "DataException.h"
#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include <iomanip>
using namespace std;

string left_string(const string& text, int width) {
    string result = text;
    if (width > result.length()) {
        result.append(width - result.length(), ' ');
    }
    return result;
}

ostream& operator<<(ostream& os, const Material& mat) {
    os << left << setw(12) << mat.date
        << setw(15) << mat.name
        << fixed << setprecision(2)
        << setw(10) << mat.volume
        << setw(10) << mat.cost;
    return os;
}

istream& operator>>(istream& is, Material& mat) {
    is >> mat.date >> mat.name >> mat.volume >> mat.cost;
    return is;
}

bool operator==(const Material& a, const Material& b) {
    return a.name == b.name && a.date == b.date &&
        a.volume == b.volume && a.cost == b.cost;
}


ostream& operator<<(ostream& os, const Foreman& foreman) {
    os << foreman.name << " (Age: " << foreman.age << ")";
    return os;
}

istream& operator>>(istream& is, Foreman& foreman) {
    is >> foreman.name >> foreman.age;
    return is;
}

bool operator==(const Foreman& a, const Foreman& b) {
    return a.name == b.name && a.age == b.age;
}

ostream& operator<<(ostream& os, const BrigadeExpense& exp) {
    os << "Brigade #" << exp.getBrigadeNumber()
        << " | Foreman: " << exp.getForeman() << "\n";

    for (const auto& mat : exp.getMaterials()) {
        os << mat << '\n';
    }
    return os;
}

istream& operator>>(istream& is, BrigadeExpense& exp) {
    int brigadeNum;
    Foreman foreman;
    int materialCount;

    if (!(is >> brigadeNum >> foreman >> materialCount)) {
        return is;
    }

    exp.setBrigadeNumber(brigadeNum);
    exp.setForeman(foreman);

    for (int i = 0; i < materialCount; ++i) {
        Material m;
        if (is >> m) {
            exp.addMaterial(m);
        }
    }

    return is;
}

bool operator==(const BrigadeExpense& a, const BrigadeExpense& b) {
    return a.getBrigadeNumber() == b.getBrigadeNumber() &&
        a.getForeman() == b.getForeman() &&
        a.getMaterials() == b.getMaterials();
}

void readFromFile(const string& filename, deque<BrigadeExpense>& records) {
    ifstream file(filename);
    if (!file.is_open()) {
        throw DataException("Error: Unable to open file: " + filename);
    }

    BrigadeExpense exp;
    while (file >> exp) {
        records.push_back(exp);
    }

    if (records.empty()) {
        throw DataException("The file is empty or contains no valid records.");
    }
}

void groupByBrigadeAndWrite(const deque<BrigadeExpense>& records, const string& filename) {
    if (records.empty()) {
        throw DataException("No data available to write to file: " + filename);
    }

    map<int, pair<Foreman, vector<Material>>> grouped;

    for (const auto& record : records) {
        int b = record.getBrigadeNumber();
        if (grouped.find(b) == grouped.end()) {
            grouped[b].first = record.getForeman();
        }
        for (const auto& mat : record.getMaterials()) {
            grouped[b].second.push_back(mat);
        }
    }

    ofstream out(filename);
    if (!out.is_open()) {
        throw DataException("Failed to open output file: " + filename);
    }

    for (const auto& pair : grouped) {
        int brigadeNumber = pair.first;
        const Foreman& foreman = pair.second.first;
        const vector<Material>& materials = pair.second.second;

        double brigadeTotal = 0;

        cout << "Brigade #" << brigadeNumber << " | Foreman: " << foreman << "\n";
        out << "Brigade #" << brigadeNumber << " | Foreman: " << foreman << "\n";

        cout << left << setw(12) << "Date"
            << setw(15) << "Material"
            << setw(10) << "Volume"
            << setw(10) << "Cost" << '\n';
        out << left << setw(12) << "Date"
            << setw(15) << "Material"
            << setw(10) << "Volume"
            << setw(10) << "Cost" << '\n';

        cout << string(47, '-') << '\n';
        out << string(47, '-') << '\n';

        for (const auto& mat : materials) {
            cout << mat << '\n';
            out << mat << '\n';
            brigadeTotal += mat.cost;
        }

        cout << "Total brigade cost: " << fixed << setprecision(2) << brigadeTotal << "\n\n";
        out << "Total brigade cost: " << fixed << setprecision(2) << brigadeTotal << "\n\n";
    }
}

void summarizeMaterials(const deque<BrigadeExpense>& records, const string& filename) {
    if (records.empty()) {
        throw DataException("No data available for material summary.");
    }

    map<string, pair<double, double>> summary;

    for (const auto& record : records) {
        for (const auto& mat : record.getMaterials()) {
            summary[mat.name].first += mat.volume;
            summary[mat.name].second += mat.cost;
        }
    }
    ofstream out(filename);
    if (!out.is_open()) {
        throw DataException("Failed to open file for material summary: " + filename);
    }

    cout << "\nMATERIAL SUMMARY\n";
    cout << left << setw(20) << "Material"
        << setw(15) << "Total Volume"
        << setw(15) << "Total Cost" << '\n';
    cout << string(50, '-') << '\n';

    out << "\nMATERIAL SUMMARY\n";
    out << left << setw(20) << "Material"
        << setw(15) << "Total Volume"
        << setw(15) << "Total Cost" << '\n';
    out << string(50, '-') << '\n';

    for (const auto& pair : summary) {
        const string& name = pair.first;
        double volume = pair.second.first;
        double cost = pair.second.second;

        cout << left << setw(20) << name
            << fixed << setprecision(2)
            << setw(15) << volume
            << setw(15) << cost << '\n';

        out << left << setw(20) << name
            << fixed << setprecision(2)
            << setw(15) << volume
            << setw(15) << cost << '\n';
    }

    cout << '\n';
    out << '\n';
}

