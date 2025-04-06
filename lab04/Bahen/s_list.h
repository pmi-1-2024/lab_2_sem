#include "list.h"
using namespace std;

class StudentList: public List{
public:
	StudentList();
	void push(Student s );
	void pop(SLink * s);
	void PrintAll();
	~StudentList(){};
};


