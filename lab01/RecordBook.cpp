#include "RecordBook.h"

ostream& operator<<(ostream& out, const RecordBook& rb) {
    out << "Залікова книжка №: " << rb.recordNumber << endl;
    for (int i = 0; i < rb.subjectCount; i++) {
        out << rb.subjects[i] << endl;
    }
    return out;
}

istream& operator>>(istream& in, RecordBook& rb) {
    cout << "Введіть номер залікової книжки: ";
    in >> rb.recordNumber;
    return in;
}
