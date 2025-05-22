#pragma once
#include "team.h"
#include "material.h"
#include <string>
#include <list>
#include <stdexcept>
using namespace std;
class FileException : public runtime_error
{
public:
	FileException(const string& msg) : runtime_error(msg) {}
};
class DataException : public runtime_error
{
public: 	
	DataException(const string& msg) : runtime_error(msg) {}
};
list <Team> readTeams();
void saveTeams(const list<Team>& teams);
void saveMaterials(const list<Material>& materials);
list <Material> summarizeMaterials(const list <Team>& teams);
void printTeams(const list <Team>& teams);
void printMaterials(const list <Material>& materials);
bool compareMaterials(const Team& a, const Team& b);
