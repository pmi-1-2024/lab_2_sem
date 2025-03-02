#include "Subject.h"
using namespace std;
ostream& operator<<(ostream& os, const Subject& subj) {
    os << subj.name << " (Semester " << subj.semester << "): " << subj.grade;
    return os;
}

istream& operator>>(istream& is, Subject& subj) {
    is >> subj.name >> subj.semester >> subj.grade;
    return is;
}



