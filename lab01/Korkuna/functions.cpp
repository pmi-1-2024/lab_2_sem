#include <conio.h>
#include "functions.h"



void get(string field, string quiry, Group* list) {
    if (field == "Group") { cout << list[stoi(quiry) - 1]; }
    else for (int j = 0; j < 4; j++) for (int i = 0; i < list[j].get_size(); i++) {
        Student s = list[j].get_list()[i];
        if (field == "Name") { if (s.get_name() == quiry) cout << s; }
        else if (field == "Zip") { if (s.get_zip() == quiry) cout << s; }
        else if (field == "ZalicId") { if (s.get_z_id() == quiry) cout << s; }
        else if (field == "Predmet") { if (s.is_in_subjects(quiry)) cout << s; }
        else { cout << "WRONG CRITERIA"; return;};
    }
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
            for (int i = 0; i < 4; i++) cout << list[i];
            _getch();
            continue;
        }
        cin >> q;
        system("cls");
        get(f, q, list);
        _getch();
    }
}