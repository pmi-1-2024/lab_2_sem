#pragma once
#include <string>
#include <map>
#include <deque>
using namespace std;

typedef deque<string> Material;  
typedef pair<string, deque<Material>> BrigadeData; 
typedef map<int, BrigadeData> BrigadeMap;