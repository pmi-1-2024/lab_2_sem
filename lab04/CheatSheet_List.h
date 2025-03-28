#ifndef CHEATSHEET_LIST_H
#define CHEATSHEET_LIST_H

#include "List.h"
#include "CheatSheet_Link.h"

class CheatSheet_List : public List {
public:
    void push(const CheatSheet& cheatsheet);
    CheatSheet_link* find(const CheatSheet& cheatsheet) const;
    void insert(const CheatSheet& cheatsheet, CheatSheet_link* after);
    void printAll() const;
};

#endif