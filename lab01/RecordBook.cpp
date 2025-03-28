#include "RecordBook.h"

ostream& operator<<(ostream& out, const RecordBook& rb) {
    out << "������� ������ �: " << rb.recordNumber << endl;
    for (int i = 0; i < rb.subjectCount; i++) {
        out << rb.subjects[i] << endl;
    }
    return out;
}

istream& operator>>(istream& in, RecordBook& rb) {
    cout << "������ ����� ������� ������: ";
    in >> rb.recordNumber;
    return in;
}
