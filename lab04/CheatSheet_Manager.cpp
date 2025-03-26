#include "CheatSheet_Manager.h"
#include <iostream>
#include "List.h"
#include "CheatSheet_List.h"
using namespace std;

void CheatSheet_Manager::addCheatSheet(const CheatSheet& cheatsheet) {
    list.push(cheatsheet);
}

void CheatSheet_Manager::removeCheatSheet(const CheatSheet& cheatsheet) {
    CheatSheet_link* node = list.find(cheatsheet);
    if (node) {
        list.remove(node);
        delete node;
        cout << "Cheat sheet is removed successfully." << endl;
    }
    else {
        cout << "Cheat sheet is not found." << endl;
    }
}

void CheatSheet_Manager::findCheatSheet(const CheatSheet& cheatsheet) const {
    CheatSheet_link* node = list.find(cheatsheet);
    if (node) {
        cout << "Found: " << node->data << endl;
    }
    else {
        cout << "Cheat sheet is not found." << endl;
    }
}

void CheatSheet_Manager::updateCheatSheet(const CheatSheet& oldCs, const CheatSheet& updatedCs) {
    CheatSheet_link* node = list.find(oldCs);
    if (node) {
        node->data = updatedCs;
        cout << "Cheat sheet is updated successfully." << endl;
    }
    else {
        cout << "Cheat sheet is not found." << endl;
    }
}

void CheatSheet_Manager::displayAll() const {
    cout << "\nAll CheatSheets:\n";
    list.printAll();
}