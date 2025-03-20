#include "Function.h"

int main() {
    Student students[2];
    int studentCount = 0;

    readStudentsFromFile("data.txt", students, studentCount);
    writeSortedCheatSheets("sorted_cheatsheets.txt", students, studentCount);
    writeElectronicCheatSheets("electronic_comp.txt", students, studentCount);

    cout << "Data has been processed. Check the files." << endl;
    return 0;
}
