
#include "BubbleSortUtils.h"

bool CompareIntLastDigit(int& a, int& b)
{
    return (a % 10) > (b % 10);
}

bool CompareDoubleIntegerPart(double& a, double& b)
{
    return static_cast<int>(a) > static_cast<int>(b);
}

bool CompareStringLength(string& a, string& b)
{
    return a.length() > b.length();
}

bool CompareStudentSurnameLength(UserType& a, UserType& b)
{
    return a.FetchSurname().length() > b.FetchSurname().length();
}

void ShowMainMenu()
{
    cout << "\nSelect the data type to sort:\n";
    cout << "0. Exit\n1. Integer\n2. Double\n3. String\n4. UserType (struct)\nYour choice: ";
}

void HandleUserChoice(int selection)
{
    size_t size;
    int* intArray = nullptr;
    double* dblArray = nullptr;
    string* strArray = nullptr;
    UserType* userArray = nullptr;
    int sortOption;

    switch (selection)
    {
    case 0:
        cout << "Exiting the program.\n";
        break;
    case 1:
        cout << "\nHow many integers? ";
        cin >> size;
        intArray = new int[size];
        FillArray(intArray, size);
        cout << "\nChoose sorting mode:\n1. Standard\n2. By last digit\nSelection: ";
        cin >> sortOption;
        if (sortOption == 1)
        {
            BubbleSortBasic(intArray, size);
        }
        else if (sortOption == 2)
        {
            BubbleSortWithCompare(intArray, size, CompareIntLastDigit);
        }
        cout << "Resulting sorted array:\n";
        DisplayArray(intArray, size);
        delete[] intArray;
        break;
    case 2:
        cout << "\nEnter number of doubles: ";
        cin >> size;
        dblArray = new double[size];
        FillArray(dblArray, size);
        cout << "\nChoose sorting mode:\n1. Standard\n2. By integer part\nSelection: ";
        cin >> sortOption;
        if (sortOption == 1)
        {
            BubbleSortBasic(dblArray, size);
        }
        else if (sortOption == 2)
        {
            BubbleSortWithCompare(dblArray, size, CompareDoubleIntegerPart);
        }
        cout << "Sorted result:\n";
        DisplayArray(dblArray, size);
        delete[] dblArray;
        break;
    case 3:
        cout << "\nHow many strings? ";
        cin >> size;
        strArray = new string[size];
        FillArray(strArray, size);
        cout << "\nSelect sort method:\n1. Alphabetical\n2. By length\nSelection: ";
        cin >> sortOption;
        if (sortOption == 1)
        {
            BubbleSortBasic(strArray, size);
        }
        else if (sortOption == 2)
        {
            BubbleSortWithCompare(strArray, size, CompareStringLength);
        }
        cout << "Here is your sorted array:\n";
        DisplayArray(strArray, size);
        delete[] strArray;
        break;
    case 4:
        cout << "\nEnter number of UserType objects: ";
        cin >> size;
        userArray = new UserType[size];
        FillArray(userArray, size);
        cout << "\nSorting option:\n1. Default\n2. By surname length\nSelection: ";
        cin >> sortOption;
        if (sortOption == 1)
        {
            BubbleSortBasic(userArray, size);
        }
        else if (sortOption == 2)
        {
            BubbleSortWithCompare(userArray, size, CompareStudentSurnameLength);
        }
        cout << "Sorted UserType objects:\n";
        DisplayArray(userArray, size);
        delete[] userArray;
        break;
    default:
        cout << "\nInvalid selection!\n";
        break;
    }
}
