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


bool Comp(const Address& a, const Address& b) {
    return a.city > b.city;
}


int main()
{
    int n = 6;



    int arr1[6] = { 2,4,1,0,5,2 };
    insertionSort<int>(arr1, n);
    print<int>(arr1, n);

    cout << "---------------" << endl;


    string arr2[6] = { "bbb","acb","aaa","abc","sdfsd","zxe"};
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
    insertionSort<Address>(arr4, 3,&Comp);
    print<Address>(arr4, 3);
    cout << "---------------" << endl;
}



