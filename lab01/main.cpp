#include <iostream>
#include "Name.h"
#include "Group.h"
#include "Address.h"
#include "Predmet.h"
#include "RecordBook.h"
#include "Student.h"
using namespace std;

int main() {
    RecordBook rb("12344242");
    rb.addSubject(Predmet("Math", 1, 5));
    rb.addSubject(Predmet("Physics", 1, 4));
    rb.addSubject(Predmet("Chemistry", 2, 3));

    Student student(Name("Alex Flash"), Group("PMI-11"), Address(123456, "Lviv", "Grikov"), rb);
    student.print();

    return 0;
}
