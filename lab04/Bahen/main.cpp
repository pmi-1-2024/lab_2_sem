
#include <iostream>
using namespace std;

class Student {
private:
    string name;
    int age;
    string group;
public:
    Student(){
    	name = "";
    	age = -1;
    	group = 1;
    }
};

class Link{
public:
	Link * next;
	Link * priv;
public:
	Link(){next = nullptr;priv = nullptr;}
	void set_next(Link * l){
		next = l;
	}
	void set_priv(Link * l){
		priv = l;
	}
	virtual ~ Link();
};

class SLink: public Link{
protected:
	Student val;
public:
	SLink():Link(){};
	SLink(Student s):Link(){val = s;};
	~ SLink();
};

class List{
protected:
	Link * head;
public:
	List(){head = nullptr;}
	bool isEmpty(){return head == nullptr;}
	virtual Link * top(){return head;}
	void push(Link * new_e){
			new_e->priv = head;
			head -> next = new_e;
			head = new_e;
	}
	void pop(){
		if(head != nullptr){
			Link * buff = head;
			head = buff->priv;
			delete buff;
		}
	}
	virtual ~ List();
};

class StudentList: public List{
public:
	StudentList():List(){};
	void Add(const Student& s ){List::push(new SLink(s));}
	~StudentList(){};
};


int main() {

}
