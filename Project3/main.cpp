#include <iostream>
#include <windows.h>
#include <vector>
#include "Student.h"

using namespace std;

// Функція для пошуку студентів за діапазоном оцінок
void searchByGradeRange(const vector<Student>& students, double minGrade, double maxGrade) {
    cout << "\nСтуденти з оцінками в діапазоні [" << minGrade << ", " << maxGrade << "]:" << endl;
    bool found = false;

    for (const auto& student : students) {
        bool hasGradeInRange = false;
        for (const auto& subject : student.recordBook.subjects) {
            if (subject.grade >= minGrade && subject.grade <= maxGrade) {
                hasGradeInRange = true;
                break;
            }
        }
        if (hasGradeInRange) {
            student.display();
            cout << "--------------------------" << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Немає студентів з оцінками у вказаному діапазоні." << endl;
    }
}

int main() {
    SetConsoleOutputCP(65001); // Установка кодування UTF-8 для виводу
    SetConsoleCP(65001);       // Установка кодування UTF-8 для введення
    setlocale(LC_ALL, "");     // Локалізація

    vector<Student> students = {
        Student("Артем Гаврилюк", Address("79000", "Львів", "Вул. Шевченка 10"), "КН-2023", RecordBook("123001")),
        Student("Олександр Іваненко", Address("02000", "Київ", "Пр. Перемоги 15"), "КБ-2023", RecordBook("123002")),
        Student("Марія Савчук", Address("58000", "Чернівці", "Вул. Головна 5"), "КІ-2023", RecordBook("123003")),
        Student("Ірина Петренко", Address("65000", "Одеса", "Фонтанська дорога 33"), "КБ-2022", RecordBook("123004")),
        Student("Дмитро Коваленко", Address("49000", "Дніпро", "Просп. Гагаріна 25"), "КН-2021", RecordBook("123005")),
        Student("Наталя Лисенко", Address("76000", "Івано-Франківськ", "Вул. Грушевського 7"), "КІ-2020", RecordBook("123006")),
        Student("Володимир Сидоренко", Address("61000", "Харків", "Московський просп. 40"), "КБ-2023", RecordBook("123007")),
        Student("Олена Мартинюк", Address("46000", "Тернопіль", "Вул. Руська 12"), "КН-2023", RecordBook("123008")),
        Student("Максим Бондаренко", Address("21000", "Вінниця", "Вул. Соборна 5"), "КІ-2022", RecordBook("123009")),
        Student("Катерина Зайцева", Address("40000", "Суми", "Вул. Петропавлівська 2"), "КБ-2021", RecordBook("123010"))
    };

    // Додаємо предмети для кожного студента
    students[0].recordBook.addSubject(Subject("Математика", 1, 85));
    students[0].recordBook.addSubject(Subject("Програмування", 2, 90));

    students[1].recordBook.addSubject(Subject("Фізика", 1, 80));
    students[1].recordBook.addSubject(Subject("Алгоритми", 2, 88));

    students[2].recordBook.addSubject(Subject("Дискретна математика", 1, 92));
    students[2].recordBook.addSubject(Subject("Бази даних", 2, 89));

    students[3].recordBook.addSubject(Subject("Лінійна алгебра", 1, 75));
    students[3].recordBook.addSubject(Subject("Комп'ютерні мережі", 2, 70));

    students[4].recordBook.addSubject(Subject("Інженерна графіка", 1, 95));
    students[4].recordBook.addSubject(Subject("Теорія ймовірностей", 2, 82));

    students[5].recordBook.addSubject(Subject("Веб-програмування", 1, 65));
    students[5].recordBook.addSubject(Subject("Програмна інженерія", 2, 78));

    students[6].recordBook.addSubject(Subject("Системне програмування", 1, 72));
    students[6].recordBook.addSubject(Subject("Штучний інтелект", 2, 98));

    students[7].recordBook.addSubject(Subject("Операційні системи", 1, 85));
    students[7].recordBook.addSubject(Subject("Машинне навчання", 2, 91));

    students[8].recordBook.addSubject(Subject("Кібербезпека", 1, 60));
    students[8].recordBook.addSubject(Subject("Big Data", 2, 88));

    students[9].recordBook.addSubject(Subject("Філософія", 1, 69));
    students[9].recordBook.addSubject(Subject("Правознавство", 2, 77));

    // Виведення всіх студентів
    cout << "Список всіх студентів:\n";
    for (const auto& student : students) {
        student.display();
        cout << "--------------------------" << endl;
    }

    // Пошук за діапазоном оцінок
    double minGrade, maxGrade;
    cout << "\nВведіть діапазон оцінок (мінімальна оцінка - максимальна оцінка): ";
    cin >> minGrade >> maxGrade;

    searchByGradeRange(students, minGrade, maxGrade);

    return 0;
}