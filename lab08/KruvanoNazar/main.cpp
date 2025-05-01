#include <iostream>
#include "Features.h"
#include <algorithm>
int main()
{
    deque<Bill*> bills;
    deque<Bill*> Gbills;
    ifstream file1("bills.txt");
    ofstream file2("billsprint.txt");
    ofstream file3("gasbills.txt");
    ofstream file4("findbills.txt");
    try {
        ReadFile(file1, bills, Gbills);
        cout << "\nBills before sorting: " << "\n";
        for (Bill* bill : bills) {
            cout << *bill << "\n";
        }
        sort(bills.begin(), bills.end(), CompareBills);
        cout << "\nBills after sorting: " << "\n";
        for (Bill* bill : bills) {
            cout << *bill << "\n";
        }
        for (Bill* bill : bills) {
            file2 << *bill << "\n";
        }
        cout << "\nOnly gas bills:" << "\n";
        for (Bill* bill : Gbills) {
            cout << *bill << "\n";
        }
        sort(Gbills.begin(), Gbills.end(), CompareBills);
        cout << "\nOnly gas bills after sorting:" << "\n";
        for (Bill* bill : Gbills) {
            cout << *bill << "\n";
        }
        for (Bill* bill : Gbills) {
            file3 << *bill << "\n";
        }
        double n;
        cout << "\nEnter a number to find bill greater than this number: ";
        cin >> n;
        cout << "\nBills:" << "\n";
        for (Bill* bill : bills) {
            if (bill->GetAmPaid() > n) {
                cout << *bill << "\n";
                file4 << *bill << "\n";
            }
        }
    }
    catch (const ifstream::failure& f) {
        cerr << "\nFile eror: " << f.what();
        return 1;
    }
    catch (const exception& ex) {
        cerr << "\nEror: " << ex.what();            
    }

    for (Bill* bill : bills) {
        delete bill;
    }
    return 0;
}
