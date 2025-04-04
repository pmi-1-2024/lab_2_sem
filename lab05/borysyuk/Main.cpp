#include <iostream>
using namespace std;
template<class T>void  insertionSort(T arr[], int n) {
    for (int i = 1; i < n; i++) {
        T key = arr[i];
        int j = i - 1;

        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
struct Address {
    string city;
    int number;

    bool operator > (const Address& other)const {
        return number > other.number;
     }
    void print()const {
        cout << city << "  " << number << endl;
    }

    friend ostream& operator<<(ostream& os, Address& a) {
        a.print();
        return os;
    }
};
template<class T>void print(T arr[], int n) {
    cout << "Sorted mas : " << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

template<class T>void  insertionSort(T arr[], int n,bool(*Comp)(const T&,const T&) ) {
    for (int i = 1; i < n; i++) {
        T key = arr[i];
        int j = i - 1;


        while (j >= 0 && Comp(arr[j] , key)) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}


bool CompSity(const Address& a, const Address& b) {
    return a.city > b.city;
}

bool CompLength(const string& a, const string& b) {
    return a.length() > b.length();
}
bool CompLastInt(const int& a, const int& b) {
    return (a % 10) > (b % 10);
}
bool CompDouble(const double& a, const double& b) {
    int a1 = a;
    int b1 = b;
    return a1 > b1;
}



int main()
{
    int n = 6;



    int arr1[6] = { 2,4,1,0,5,2 };
    insertionSort<int>(arr1, n);
    print<int>(arr1, n);

    cout << "---------------" << endl;


    string arr2[6] = { "bb","acb","aaa","a","sfsdii","zxei"};
    insertionSort<string>(arr2, n);
    print<string>(arr2, n);

    cout << "---------------" << endl;

    double arr3[6] = { 2.0 , 4.5 ,11.3 ,4.0 , 6.5 , 2.1 };
    insertionSort<double>(arr3, n);
    print<double>(arr3, n);

    cout << "---------------" << endl;

    Address arr4[3] = { {"lviv",11},{"Odesa",2},{"Kuiv",3}};
    insertionSort<Address>(arr4, 3);
    print<Address>(arr4, 3);

    cout << "---------------" << endl;
    insertionSort<Address>(arr4, 3,&CompSity);
    print<Address>(arr4, 3);
    cout << "---------------" << endl;

    string arr5[6] = { "bb","acb","aaa","a","sfsdii","zxei" };
    insertionSort<string>(arr5, n, &CompLength);
    print<string>(arr5, n);

    cout << "---------------" << endl;

    int arr6[6] = { 25,41,10,0,52,24 };
    insertionSort<int>(arr6, n,&CompLastInt);
    print<int>(arr6, n);

    cout << "---------------" << endl;

    double arr7[6] = { 2.0 , 4.5 ,11.3 ,4.0 , 6.5 , 2.1 };
    insertionSort<double>(arr7, n,&CompDouble);
    print<double>(arr7, n);

    cout << "---------------" << endl;
}



