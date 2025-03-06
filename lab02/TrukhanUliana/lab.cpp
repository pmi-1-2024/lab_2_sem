#include "Utils.h"

int main() {
    ifstream file("Data.txt");

    HouseElectronic* electronics[7];
    int count = 0;
    readFromFile(file, electronics, count);
   
    file.close();

    ofstream file1("File1.txt");
    writeSorted(file1, electronics, count);
    file1.close();

    ofstream file2("File2.txt");
    string firm;
    cout << "Enter firm name: ";
    cin >> firm;
    writeFirmToFile(file2, electronics, count, firm);
    file2.close();

    for (int i = 0; i < count; i++) {
        delete electronics[i];
    }

    return 0;
}
