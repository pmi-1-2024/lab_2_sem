#ifndef CHEATSHEET_MANAGER_H
#define CHEATSHEET_MANAGER_H

#include "CheatSheet_List.h"

class CheatSheet_Manager {
    CheatSheet_List list;

public:
    void addCheatSheet(const CheatSheet& cheatsheet);
    void removeCheatSheet(const CheatSheet& cheatsheet);
    void findCheatSheet(const CheatSheet& cheatsheet) const;
    void updateCheatSheet(const CheatSheet& oldCs, const CheatSheet& updatedCs);
    void displayAll() const;
};

#endif