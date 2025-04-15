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

    studentManager.add(Student("�� ������", Adress(12335, "����", "��������� 15"), "���-43", Zalik(0, 0)));
    studentManager.add(Student("����� ³�����", Adress(74521, "������", "������������ 88"), "�г-11", Zalik(0, 0)));

    studentManager.print();

    studentManager.findName("�� ������");
    studentManager.replace("�� ������", Student("����� ��������", Adress(21342, "���", "������ 12"), "���-21", Zalik(0, 0)));

    studentManager.print();

    studentManager.remove(Student("����� ³�����", Adress(74521, "������", "������������ 88"), "�г-11", Zalik(0, 0)));

    studentManager.print();

    return 0;
}