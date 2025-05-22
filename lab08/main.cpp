#include "utils.h"
#include <iostream>
int main() {
	try {
		list<Team> teams = readTeams();
		printTeams(teams);
		list<Material> materialsSummary = summarizeMaterials(teams);
		printMaterials(materialsSummary);
		saveTeams(teams);
		saveMaterials(materialsSummary);

		cout << "\nData processing completed successfully!\n";
		cout << "Results saved to teams.txt and materials.txt\n";
	}
	catch (const FileException& e) {
		cout << "File error: " << e.what() << endl;
	}
	catch (const DataException& e) {
		cout << "Data error: " << e.what() << endl;
	}
	catch (const exception& e) {
		cout << "Unexpected error: " << e.what() << endl;
	}
	return 0;
}