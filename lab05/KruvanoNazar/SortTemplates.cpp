#include <iostream>
#include "Features.h"
using namespace std;

int main() {
    int choice;
    do {
        startmenu();
        cin >> choice;
        Arraymenu(choice);
    } while (choice != 0);
    return 0;
};