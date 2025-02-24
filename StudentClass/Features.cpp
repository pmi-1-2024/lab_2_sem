#include "Features.h"

void menu() {
    cout << "Choose number of search criteria:" << endl;
    cout << "1. By srudent name" << endl;
    cout << "2. By student city (address)" << endl;
    cout << "3. By academic group" << endl;
    cout << "4. By zalikovka number" << endl;
    cout << "5. By subject name" << endl;
    cout << "6. By semester" << endl;
    cout << "Enter choice: ";
}

void readFile(ifstream& file, int& studentCount, Student students[]) {
    while (file.is_open() && studentCount < 100) {
       
        string name, index, city, street, group, recnumber;
        file >> name >> index >> city >> street >> group >> recnumber;

        Adresa address(index, city, street);
        Zalikovka recordBook(recnumber);

        string subjectName, semester;
        int grade;
        while (file >> subjectName) {
            if (subjectName == "END") break;
            file >> semester >> grade;
            recordBook.addSub(Predmet(subjectName, semester, grade));
        }

        students[studentCount++] = Student(name, address, group, recordBook);
    }
}