#include <iostream>
#include <fstream>
#include <conio.h>
#include "Student.h"
using namespace std;

void get(string field, string quiry, Student * list) {
    if (field == "Name") { for (int i = 0; i < 10; i++) if (list[i].get_name() == quiry) cout << list[i]; }
    else if (field == "Zip") { for (int i = 0; i < 10; i++) if (list[i].get_zip() == quiry) cout << list[i]; }
    else if (field == "Group") { for (int i = 0; i < 10; i++) if (list[i].get_group() == quiry) cout << list[i]; }
    else if (field == "ZalicId") { for (int i = 0; i < 10; i++) if (list[i].get_z_id() == quiry) cout << list[i]; }
    else if (field == "Predmet") { for (int i = 0; i < 10; i++) if (list[i].get_z_id() == quiry) cout << list[i]; }
    else cout << "WRONG CRITERIA";
}
void search(Student * list) {
    string f, q;
    while (true) {
        system("cls");
        cout << "Possible criteria - Name, Zip, Group, ZalicId, Predmet" << endl << "All Students - All" << endl << "Stop Seraching - End" << endl << "Quiry: ";

        cin >> f;
        if (f == "End") break;
        if (f == "All") {
            system("cls");
            for (int i = 0; i < 10; i++) cout << list[i];
            _getch();
            continue;
        }
        cin >> q;
        system("cls");
        get(f, q, list);
        _getch();
    }
}
int main()
{
    
    ifstream inp("dateee.txt");
    cout << inp.is_open();
    Student list[10];
    for (int i = 0; i < 10; i++) inp >> list[i];
    search(list);
    return 0;
}
