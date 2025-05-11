#include <iostream>
#include "BubbleSortUtils.h"
using namespace std;

int main() {
    int userInput = -1;
    do
    {
        ShowMainMenu();
        cin >> userInput;
        HandleUserChoice(userInput);
    } while (userInput != 0);
    return 0;
}
