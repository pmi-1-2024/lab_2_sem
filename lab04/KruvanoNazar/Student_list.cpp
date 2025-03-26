#include "Student_list.h"

void Student_list::push(Student s)
{
	Student_link* temp = new Student_link(s);
	List::push(temp);
}

Student_link* Student_list::top() const
{
	return (Student_link*)head;
}

Student_link* Student_list::find(const Student& s)
{
	Student_link* temp = (Student_link*)head;
	while (temp) {
		if (temp->data.GetName() == s.GetName()&& temp->data.GetGroup() == s.GetGroup()&&temp->data.GetAvM()==s.GetAvM())
			return temp;
		temp = (Student_link*)(temp->next);
	}
	return 0;
}

void Student_list::insert(Student a, Student_link* after)
{
	if (!after) return; 
	Student_link* newnode = new Student_link(a);
	newnode->next = after->next;
	after->next = newnode;
}


