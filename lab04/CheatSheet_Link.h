#ifndef CHEATSHEET_LINK_H
#define CHEATSHEET_LINK_H
#include "Link.h"
#include "CheatSheet.h"

struct CheatSheet_link : Link { 
	CheatSheet data;
	CheatSheet_link(const CheatSheet& cheatsheet) : data(cheatsheet) {}
};
#endif