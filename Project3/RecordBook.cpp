#include "RecordBook.h"
void RecordBook::addSubject(Subject s) {
    subjects.push_back(s);
}
void RecordBook::display() const {
    cout << "Залікова книжка №: " << recordNumber << endl;
    for (const auto& sub : subjects) {
        sub.display();
    }
}
