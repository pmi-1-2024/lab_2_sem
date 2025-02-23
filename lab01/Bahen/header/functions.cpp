#include <conio.h>
#include "functions.h"
#include "constants.h"


void get(string field, string quiry, Group* list) {
    if (field == "Name") { for (int j = 0; j < k; j++) for (int i = 0; i < list[j].get_size(); i++) if (list[j].get_list()[i].get_name() == quiry) cout << list[j].get_list()[i]; }
    else if (field == "Zip") { for (int j = 0; j < k; j++) for (int i = 0; i < list[j].get_size(); i++) if (list[j].get_list()[i].get_zip() == quiry) cout << list[j].get_list()[i]; }
    else if (field == "Group") { cout << list[stoi(quiry)-1]; }
    else if (field == "ZalicId") { for (int j = 0; j < k; j++) for (int i = 0; i < list[j].get_size(); i++) if (list[j].get_list()[i].get_z_id() == quiry) cout << list[j].get_list()[i]; }
    else if (field == "Predmet") { for (int j = 0; j < k; j++) for (int i = 0; i < list[j].get_size(); i++) if (list[j].get_list()[i].is_in_subjects(quiry)) cout << list[j].get_list()[i]; }
    else cout << "WRONG CRITERIA";
}

void search(Group* list) {
    string f, q;
    while (true) {
        system("cls");
        cout << "Possible criteria - Name, Zip, Group, ZalicId, Predmet" << endl << "All Students - All" << endl << "Stop Seraching - End" << endl << "Quiry: ";

        cin >> f;
        if (f == "End") break;
        if (f == "All") {
            system("cls");
            for (int i = 0; i < n; i++) cout << list[i];
            _getch();
            continue;
        }
        cin >> q;
        system("cls");
        get(f, q, list);
        _getch();
    }
}