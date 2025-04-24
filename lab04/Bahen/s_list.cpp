#include "s_list.h"

StudentList::StudentList():List(){};

void StudentList::push(Student s ){List::push(new SLink(nullptr,s));}

void StudentList::pop(SLink * s){List::pop(s);}


