#include "Features.h"

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
        cout << "\nEnter a type of BubbleSort fuction you want to sort array: " << "\n1.Normal function" << "\n2.With Comp()";
        cout << "\nEnter choice:";
        cin >> sorttype;
        if (sorttype == 1) BubbleSort1(intarr, arraysize);
        else if (sorttype == 2) BubbleSort2(intarr, arraysize,Comp<int>);
        cout << "\nSorted array: ";
        PrintArr(intarr, arraysize);
        delete[] intarr;
        break;

    case 2:
        cout << "\nEnter a number of elements: ";
        cin >> arraysize;
        doublearr = new double[arraysize];
        EnterElem(doublearr, arraysize);
        cout << "\nEnter a type of BubbleSort fuction you want to sort array: " << "\n1.Normal function" << "\n2.With Comp()";
        cout << "\nEnter choice:";
        cin >> sorttype;
        if (sorttype == 1) BubbleSort1(doublearr, arraysize);
        else if (sorttype == 2) BubbleSort2(doublearr, arraysize, Comp<double>);
        cout << "\nSorted array: ";
        PrintArr(doublearr, arraysize);
        delete[] doublearr;
        break;

    case 3:
        cout << "\nEnter a number of elements: ";
        cin >> arraysize;
        strarray = new string[arraysize];
        EnterElem(strarray, arraysize);
        cout << "\nEnter a type of BubbleSort fuction you want to sort array: " << "\n1.Normal function" << "\n2.With Comp()";
        cout << "\nEnter choice:";
        cin >> sorttype;
        if (sorttype == 1) BubbleSort1(strarray, arraysize);
        else if (sorttype == 2) BubbleSort2(strarray, arraysize, Comp<string>);
        cout << "\nSorted array: ";
        PrintArr(strarray, arraysize);
        delete[] strarray;
        break;

    case 4:
        cout << "\nEnter a number of elements: ";
        cin >> arraysize;
        studarray = new Student[arraysize];
        EnterElem(studarray, arraysize);
        cout << "\nEnter a type of BubbleSort fuction you want to sort array: " << "\n1.Normal function" << "\n2.With Comp()";
        cout << "\nEnter choice:";
        cin >> sorttype;
        if (sorttype == 1) BubbleSort1(studarray, arraysize);
        else if (sorttype == 2) BubbleSort2(studarray, arraysize, Comp<Student>);
        cout << "\nSorted array: ";
        PrintArr(studarray, arraysize);
        delete[] studarray;
        break;

    default:
        cout << "\nInvalid choice!";
    }
}

