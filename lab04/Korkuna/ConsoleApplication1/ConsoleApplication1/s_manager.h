#include "s_list.h"

class StudentManager {

	StudentList list;
public:
	StudentManager() {};
	SLink* find(int id);

	void add(Student s);
	void del(int id_to_del);

	void rewrite(int id_to_change);
	void printAll();
};