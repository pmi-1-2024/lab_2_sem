#include <iostream>
#include "FileUtils.h"
#include "SummaryUtils.h"

using namespace std;

int main() {
    try {
        vector<TeamData> rawData = readFromFile("materials.txt");

        map<int, TeamData> merged;
        mergeTeams(rawData, merged);

        saveTeamsToFile(merged, "teams_output.txt");

        map<string, MaterialSummary> summary;
        summarizeMaterials(merged, summary);

        saveSummaryToFile(summary, "summary_output.txt");

        cout << " Processing complete. Data saved to files." << endl;
    }
    catch (const exception& ex) {
        cerr << "❌ Error: " << ex.what() << endl;
    }

    return 0;
}
