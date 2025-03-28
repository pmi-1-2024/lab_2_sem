#include "CheatSheet_List.h"
#include <iostream>
using namespace std;

void CheatSheet_List::push(const CheatSheet& cheatsheet) {
    CheatSheet_link* temp = new CheatSheet_link(cheatsheet);
    List::push(temp);
}

CheatSheet_link* CheatSheet_List::find(const CheatSheet& cheatsheet) const {
    CheatSheet_link* temp = (CheatSheet_link*)head;
    while (temp) {
        if (temp->data.subject == cheatsheet.subject && temp->data.number == cheatsheet.number) {
            return temp;
        }
        temp = (CheatSheet_link*)temp->next;
    }
    return 0;
}

void CheatSheet_List::insert(const CheatSheet& cheatsheet, CheatSheet_link* after) {
    if (!after) return;
    CheatSheet_link* temp = new CheatSheet_link(cheatsheet);
    temp->next = after->next;
    after->next = temp;
}

void CheatSheet_List::printAll() const {
    CheatSheet_link* temp = (CheatSheet_link*)head;
    while (temp) {
        cout << temp->data << endl;
        temp = (CheatSheet_link*)temp->next;
    }
}