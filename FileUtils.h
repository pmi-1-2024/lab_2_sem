#pragma once
#include "TeamData.h"
#include <string>
#include <vector>
#include <map>

vector<TeamData> readFromFile(const string& filename);
void mergeTeams(const vector<TeamData>& teams, map<int, TeamData>& merged);
void saveTeamsToFile(const map<int, TeamData>& merged, const string& filename);
