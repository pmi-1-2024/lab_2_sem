#include "Features.h"

bool intComp(int& first, int& second)
{
    return first%10 > second%10;
}

bool doubleComp(double& first, double& second)
{
    int fi = first;
    int si = second;
    return fi > si;
}

bool stringComp(string& first, string&second)
{
    return first.length() > second.length();
}

bool studentsurnameComp(Student& first, Student& second)
{
    return first.GetSurname().length() > second.GetSurname().length();
}

void startmenu()
{
    cout << "\n Enter number to choose type of array: ";
    cout << "\n0.Close menu" << "\n1.Int" << "\n2.Double" << "\n3.String" << "\n4.Student struct";
    cout << "\nEnter your choice: ";
}

void Arraymenu(int choice)
{

    size_t arraysize;
    int* intarr = nullptr;
    double* doublearr = nullptr;
    string* strarray = nullptr;
    Student* studarray = nullptr;
    int sorttype;

    switch (choice) {
    case 0:
        cout << "\nBye Bye, have a nice day!";
        break;

    case 1:
        cout << "\nEnter a number of elements: ";
        cin >> arraysize;
        intarr = new int[arraysize];
        EnterElem(intarr, arraysize);
        cout << "\nEnter a type of BubbleSort fuction you want to sort array: " << "\n1.Normal sort" << "\n2.Sort by last digit";
        cout << "\nEnter choice:";
        cin >> sorttype;
        if (sorttype == 1) BubbleSort1(intarr, arraysize);
        else if (sorttype == 2) BubbleSort2(intarr, arraysize,intComp);
        cout << "\nSorted array: ";
        PrintArr(intarr, arraysize);
        delete[] intarr;
        break;

    case 2:
        cout << "\nEnter a number of elements: ";
        cin >> arraysize;
        doublearr = new double[arraysize];
        EnterElem(doublearr, arraysize);
        cout << "\nEnter a type of BubbleSort fuction you want to sort array: " << "\n1.Normal function" << "\n2.Sort by integer part";
        cout << "\nEnter choice:";
        cin >> sorttype;
        if (sorttype == 1) BubbleSort1(doublearr, arraysize);
        else if (sorttype == 2) BubbleSort2(doublearr, arraysize, doubleComp);
        cout << "\nSorted array: ";
        PrintArr(doublearr, arraysize);
        delete[] doublearr;
        break;

    case 3:
        cout << "\nEnter a number of elements: ";
        cin >> arraysize;
        strarray = new string[arraysize];
        EnterElem(strarray, arraysize);
        cout << "\nEnter a type of BubbleSort fuction you want to sort array: " << "\n1.Sorting alphabetically" << "\n2.Sort by string length";
        cout << "\nEnter choice:";
        cin >> sorttype;
        if (sorttype == 1) BubbleSort1(strarray, arraysize);
        else if (sorttype == 2) BubbleSort2(strarray, arraysize, stringComp);
        cout << "\nSorted array: ";
        PrintArr(strarray, arraysize);
        delete[] strarray;
        break;

    case 4:
        cout << "\nEnter a number of elements: ";
        cin >> arraysize;
        studarray = new Student[arraysize];
        EnterElem(studarray, arraysize);
        cout << "\nEnter a type of BubbleSort fuction you want to sort array: " << "\n1.Normal function" << "\n2.Sort by surname length";
        cout << "\nEnter choice:";
        cin >> sorttype;
        if (sorttype == 1) BubbleSort1(studarray, arraysize);
        else if (sorttype == 2) BubbleSort2(studarray, arraysize, studentsurnameComp);
        cout << "\nSorted array: ";
        PrintArr(studarray, arraysize);
        delete[] studarray;
        break;

    default:
        cout << "\nInvalid choice!";
    }
}

