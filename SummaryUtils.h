#pragma once
#include "TeamData.h"
#include <string>
#include <map>

void summarizeMaterials(const map<int, TeamData>& merged, map<string, MaterialSummary>& summary);
void saveSummaryToFile(const map<string, MaterialSummary>& summary, const string& filename);
