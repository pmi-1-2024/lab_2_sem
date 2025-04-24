#include "Student.h"
#include "Search.h"
#include "Menu.h"
#include "Group.h"
#include "File.h"
#include "Student_Manager.h"
#include <iostream>
#include <Windows.h>
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Student_Manager studentManager;

    studentManager.add(Student("Ян Малина", Adress(12335, "Львів", "Леменська 15"), "АФж-43", Zalik(0, 0)));
    studentManager.add(Student("Олесь Вільдум", Adress(74521, "Камінна", "Валентинська 88"), "ГРі-11", Zalik(0, 0)));

    studentManager.print();

    studentManager.findName("Ян Малина");
    studentManager.replace("Ян Малина", Student("Остап Розмарин", Adress(21342, "Київ", "Шалена 12"), "ХНу-21", Zalik(0, 0)));

    studentManager.print();

    studentManager.remove(Student("Олесь Вільдум", Adress(74521, "Камінна", "Валентинська 88"), "ГРі-11", Zalik(0, 0)));

    studentManager.print();

    return 0;
}