#pragma once
#include <string>
#include <map>
#include <deque>
using namespace std;

class Material {
public:
    deque<string> data;

    Material() = default;
    Material(const string& date, const string& name, int volume, double cost) {
        data.push_back(date);
        data.push_back(name);
        data.push_back(to_string(volume));
        data.push_back(to_string(cost));
    }

    const string& operator[](size_t index) const {return data.at(index);}
};
class BrigadeData {
public:
    string chief;
    deque<Material> materials;

    BrigadeData() = default;
    BrigadeData(const string& chief):chief(chief) {}

    void addMaterial(const Material& mat) {
        materials.push_back(mat);
    }
};
class BrigadeMap {
private:
    map<int, BrigadeData> data;

public:
    BrigadeData& operator[](int number) {
        return data[number];
    }

    const BrigadeData& at(int number) const {
        return data.at(number);
    }

    auto begin() const {return data.begin();}
    auto end() const {return data.end();}
    auto begin() {return data.begin();}
    auto end() {return data.end();}

    map<int, BrigadeData>& getData() {return data;}
};
