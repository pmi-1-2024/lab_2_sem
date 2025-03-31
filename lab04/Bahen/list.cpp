#include "list.h"
List::List(){head = nullptr;}
bool List::isEmpty(){return head == nullptr;}
Link * List:: top(){return head;}
void List::push(Link * new_e){
		new_e->next = head;
		head = new_e;
}
void List::pop(Link * to_del){

	Link * curr = head;

	while(curr->next != to_del)
		if(curr->next == nullptr) return;
		else curr = curr->next;

	Link * buff = curr->next;
	curr->next = curr->next->next;
	delete buff;
}
