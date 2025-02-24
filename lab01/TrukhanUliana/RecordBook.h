#ifndef RECORDBOOK_H
#define RECORDBOOK_H
#include "Subject.h"
using namespace std;

class RecordBook {
private:
    string recordNumber;
    Subject* subjects;
    int subjectCount;
public:
	RecordBook();
    RecordBook(string recordNumber, Subject* subject, int subjectCount);
	~RecordBook();

    void addSubject(Subject subject);

    string getRecordNumber() const;
	int getSubjectCount() const;
	Subject* getSubjects() const;

    bool hasSubject(string subjectName) const;
    bool hasSemester(string semester) const;

	friend istream& operator>>(istream& is, RecordBook& recordBook);
	friend ostream& operator<<(ostream& os, const RecordBook& recordBook);
};
#endif
