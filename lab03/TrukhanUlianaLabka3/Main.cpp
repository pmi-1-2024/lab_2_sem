#include "Utils.h"

int main() {
    ifstream file("Data.txt");
    HouseElectronic* electronics[10];
    int count = 0;
    readFromFile(file, electronics, count);
    file.close();

    int searchType;
    do {
        menu();
        cout << "Enter search type: ";
        cin >> searchType;

        switch (searchType) {
        case 1:
        case 2:
        case 5: {
            string searchValue;
            cin.ignore();
            cout << "Enter search value: ";
            cin >> searchValue;
            bool found = false;
            for (int i = 0; i < 10; i++) {
                if (electronics[i]->matchesCriteria(searchType, searchValue)) {
                    cout << *electronics[i] << endl;
                    found = true;
                }
            }
            if (!found) {
                cout << "No device found with the given criteria." << endl;
            }
            break;
        }

        case 3:
        case 4:
        case 6:
        case 7:
        case 8:
        case 9: {
            size_t searchValueNum;
            cout << "Enter search value: ";
            cin >> searchValueNum;
            bool found = false;
            for (int i = 0; i < 10; i++) {
                if (electronics[i]->matchesCriteriaNum(searchType, searchValueNum)) {
                    cout << *electronics[i] << endl;
                    found = true;
                }
            }
            if (!found) {
                cout << "No device found with the given criteria." << endl;
            }
            break;
        }

        case 10: {
            ofstream file1("File1.txt");
            writeSorted(file1, electronics, count);
            file1.close();
            break;
        }

        case 11: {
            ofstream file2("File2.txt");
            string firm;
            cout << "Enter firm name: ";
            cin >> firm;
            writeFirmToFile(file2, electronics, count, firm);
            file2.close();
            break;
        }

        default:
            cout << "Invalid search type." << endl;
            break;
        }



     
    } while (searchType != 0);

    for (int i = 0; i < count; i++) {
        delete electronics[i];
    }

    return 0;
}
